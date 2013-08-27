package com.rockwellcollins.atc.resolute;

import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.xtext.ISetup;

import com.google.inject.Guice;
import com.google.inject.Injector;

/**
 * Generated from StandaloneSetup.xpt!
 */
@SuppressWarnings("all")
public class ResoluteStandaloneSetupGenerated implements ISetup {

    public Injector createInjectorAndDoEMFRegistration() {
        org.osate.xtext.aadl2.properties.PropertiesStandaloneSetup.doSetup();

        Injector injector = createInjector();
        register(injector);
        return injector;
    }

    public Injector createInjector() {
        return Guice.createInjector(new com.rockwellcollins.atc.resolute.ResoluteRuntimeModule());
    }

    public void register(Injector injector) {
        if (!EPackage.Registry.INSTANCE
                .containsKey("http://www.rockwellcollins.com/atc/resolute/Resolute")) {
            EPackage.Registry.INSTANCE.put("http://www.rockwellcollins.com/atc/resolute/Resolute",
                    com.rockwellcollins.atc.resolute.resolute.ResolutePackage.eINSTANCE);
        }

        org.eclipse.xtext.resource.IResourceFactory resourceFactory = injector
                .getInstance(org.eclipse.xtext.resource.IResourceFactory.class);
        org.eclipse.xtext.resource.IResourceServiceProvider serviceProvider = injector
                .getInstance(org.eclipse.xtext.resource.IResourceServiceProvider.class);
        Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("resolute",
                resourceFactory);
        org.eclipse.xtext.resource.IResourceServiceProvider.Registry.INSTANCE
                .getExtensionToFactoryMap().put("resolute", serviceProvider);

    }
}