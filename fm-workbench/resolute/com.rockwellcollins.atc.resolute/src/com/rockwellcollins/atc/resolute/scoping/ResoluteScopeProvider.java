/*
 * generated by Xtext
 */
package com.rockwellcollins.atc.resolute.scoping;

import java.util.HashSet;
import java.util.Set;

import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EReference;
import org.eclipse.xtext.scoping.IScope;
import org.eclipse.xtext.scoping.Scopes;
import org.osate.aadl2.AadlPackage;
import org.osate.aadl2.AnnexLibrary;
import org.osate.aadl2.Classifier;
import org.osate.aadl2.ComponentClassifier;
import org.osate.aadl2.ComponentImplementation;
import org.osate.aadl2.Element;
import org.osate.aadl2.Subcomponent;
import org.osate.aadl2.ThreadSubcomponent;
import org.osate.aadl2.impl.DataPortImpl;
import org.osate.aadl2.impl.FeatureGroupImpl;
import org.osate.xtext.aadl2.properties.scoping.PropertiesScopeProvider;

import com.rockwellcollins.atc.resolute.resolute.FilterMapExpr;
import com.rockwellcollins.atc.resolute.resolute.FunctionDefinition;
import com.rockwellcollins.atc.resolute.resolute.NestedDotID;
import com.rockwellcollins.atc.resolute.resolute.ProveStatement;
import com.rockwellcollins.atc.resolute.resolute.QuantifiedExpr;
import com.rockwellcollins.atc.resolute.resolute.ResoluteSubclause;

/**
 * This class contains custom scoping description.
 * 
 * see : http://www.eclipse.org/Xtext/documentation/latest/xtext.html#scoping on
 * how and when to use it
 * 
 */
public class ResoluteScopeProvider extends PropertiesScopeProvider {
    IScope scope_NamedElement(QuantifiedExpr ctx, EReference ref) {
        return Scopes.scopeFor(ctx.getArgs(), getScope(ctx.eContainer(), ref));
    }

    IScope scope_NamedElement(FunctionDefinition ctx, EReference ref) {
        return Scopes.scopeFor(ctx.getArgs(), getScope(ctx.eContainer(), ref));
    }

    IScope scope_NamedElement(FilterMapExpr ctx, EReference ref) {
        return Scopes.scopeFor(ctx.getArgs(), getScope(ctx.eContainer(), ref));
    }
    
    
    IScope scope_NamedElement(ProveStatement ctx, EReference ref) {
        EObject container = ctx.eContainer();
        assert(container instanceof ResoluteSubclause);
        container = container.eContainer();
        if(container instanceof ComponentImplementation){
            ComponentImplementation compImpl = (ComponentImplementation)container;
            return Scopes.scopeFor(compImpl.getAllModes(),  getScope(ctx.eContainer(), ref));
        }
        return getScope(ctx.eContainer(), ref);
    }
    
    
    IScope scope_NamedElement(NestedDotID ctx, EReference ref) {
        Set<Element> components = getCorrespondingAadlElement(ctx);
        return Scopes.scopeFor(components, getScope(ctx.eContainer(), ref));
    }

    
    private Set<Element> getCorrespondingAadlElement(NestedDotID id) {
        EObject container = id.eContainer();

        if (container instanceof NestedDotID) {
            NestedDotID parent = (NestedDotID) container;
            EList<EObject> refs = parent.eCrossReferences();

            if (refs.size() != 1) {
                return new HashSet<>(); // this will throw a parsing error
            }
            container = refs.get(0);

            if (container instanceof Subcomponent) {
                if(container instanceof ThreadSubcomponent){
                    container = ((ThreadSubcomponent)container).getThreadSubcomponentType();
                }else{
                    container = ((Subcomponent) container).getComponentImplementation();
                }
            } else {
                return new HashSet<>(); // this will throw a parsing error
            }
            
        } else {
            // travel out of the annex and get the component
            // classifier that the annex is contained in.
            while (!(container instanceof ComponentClassifier)) {
                container = container.eContainer();
            }
        }

        if (container == null) {
            return new HashSet<>(); // this will throw a parsing error
        }

        Set<Element> result = new HashSet<>();

        if (container instanceof ComponentClassifier) {
            ComponentClassifier compImpl = (ComponentClassifier) container;
            if(id.getSub() == null){
                result.addAll(compImpl.getAllModes());
            }else{
                assert(compImpl instanceof ComponentImplementation);
                result.addAll(((ComponentImplementation)compImpl).getAllSubcomponents());
            }
        } else {
            assert(false);
        }


        return result;
    }
    
    
}