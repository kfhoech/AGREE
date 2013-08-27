/**
 */
package com.rockwellcollins.atc.resolute.resolute.impl;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;
import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.osate.aadl2.impl.ElementImpl;

import com.rockwellcollins.atc.resolute.resolute.Expr;
import com.rockwellcollins.atc.resolute.resolute.ProveStatement;
import com.rockwellcollins.atc.resolute.resolute.ResolutePackage;

/**
 * <!-- begin-user-doc --> An implementation of the model object '
 * <em><b>Prove Statement</b></em>'. <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 * <li>
 * {@link com.rockwellcollins.atc.resolute.resolute.impl.ProveStatementImpl#getExpr
 * <em>Expr</em>}</li>
 * </ul>
 * </p>
 * 
 * @generated
 */
public class ProveStatementImpl extends ElementImpl implements ProveStatement {
    /**
     * The cached value of the '{@link #getExpr() <em>Expr</em>}' containment
     * reference. <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @see #getExpr()
     * @generated
     * @ordered
     */
    protected Expr expr;

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    protected ProveStatementImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    protected EClass eStaticClass() {
        return ResolutePackage.Literals.PROVE_STATEMENT;
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public Expr getExpr() {
        return expr;
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    public NotificationChain basicSetExpr(Expr newExpr, NotificationChain msgs) {
        Expr oldExpr = expr;
        expr = newExpr;
        if (eNotificationRequired()) {
            ENotificationImpl notification = new ENotificationImpl(this, Notification.SET,
                    ResolutePackage.PROVE_STATEMENT__EXPR, oldExpr, newExpr);
            if (msgs == null) {
                msgs = notification;
            } else {
                msgs.add(notification);
            }
        }
        return msgs;
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public void setExpr(Expr newExpr) {
        if (newExpr != expr) {
            NotificationChain msgs = null;
            if (expr != null) {
                msgs = ((InternalEObject) expr).eInverseRemove(this, EOPPOSITE_FEATURE_BASE
                        - ResolutePackage.PROVE_STATEMENT__EXPR, null, msgs);
            }
            if (newExpr != null) {
                msgs = ((InternalEObject) newExpr).eInverseAdd(this, EOPPOSITE_FEATURE_BASE
                        - ResolutePackage.PROVE_STATEMENT__EXPR, null, msgs);
            }
            msgs = basicSetExpr(newExpr, msgs);
            if (msgs != null) {
                msgs.dispatch();
            }
        } else if (eNotificationRequired()) {
            eNotify(new ENotificationImpl(this, Notification.SET,
                    ResolutePackage.PROVE_STATEMENT__EXPR, newExpr, newExpr));
        }
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID,
            NotificationChain msgs) {
        switch (featureID) {
        case ResolutePackage.PROVE_STATEMENT__EXPR:
            return basicSetExpr(null, msgs);
        }
        return super.eInverseRemove(otherEnd, featureID, msgs);
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public Object eGet(int featureID, boolean resolve, boolean coreType) {
        switch (featureID) {
        case ResolutePackage.PROVE_STATEMENT__EXPR:
            return getExpr();
        }
        return super.eGet(featureID, resolve, coreType);
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public void eSet(int featureID, Object newValue) {
        switch (featureID) {
        case ResolutePackage.PROVE_STATEMENT__EXPR:
            setExpr((Expr) newValue);
            return;
        }
        super.eSet(featureID, newValue);
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public void eUnset(int featureID) {
        switch (featureID) {
        case ResolutePackage.PROVE_STATEMENT__EXPR:
            setExpr((Expr) null);
            return;
        }
        super.eUnset(featureID);
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public boolean eIsSet(int featureID) {
        switch (featureID) {
        case ResolutePackage.PROVE_STATEMENT__EXPR:
            return expr != null;
        }
        return super.eIsSet(featureID);
    }

} // ProveStatementImpl