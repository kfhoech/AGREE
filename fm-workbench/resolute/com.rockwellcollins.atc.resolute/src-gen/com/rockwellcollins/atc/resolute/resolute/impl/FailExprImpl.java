/**
 */
package com.rockwellcollins.atc.resolute.resolute.impl;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;
import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.osate.aadl2.StringLiteral;

import com.rockwellcollins.atc.resolute.resolute.FailExpr;
import com.rockwellcollins.atc.resolute.resolute.ResolutePackage;

/**
 * <!-- begin-user-doc --> An implementation of the model object '
 * <em><b>Fail Expr</b></em>'. <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 * <li>
 * {@link com.rockwellcollins.atc.resolute.resolute.impl.FailExprImpl#getVal
 * <em>Val</em>}</li>
 * </ul>
 * </p>
 * 
 * @generated
 */
public class FailExprImpl extends ExprImpl implements FailExpr {
    /**
     * The cached value of the '{@link #getVal() <em>Val</em>}' containment
     * reference. <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @see #getVal()
     * @generated
     * @ordered
     */
    protected StringLiteral val;

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    protected FailExprImpl() {
        super();
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    protected EClass eStaticClass() {
        return ResolutePackage.Literals.FAIL_EXPR;
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    @Override
    public StringLiteral getVal() {
        return val;
    }

    /**
     * <!-- begin-user-doc --> <!-- end-user-doc -->
     * 
     * @generated
     */
    public NotificationChain basicSetVal(StringLiteral newVal, NotificationChain msgs) {
        StringLiteral oldVal = val;
        val = newVal;
        if (eNotificationRequired()) {
            ENotificationImpl notification = new ENotificationImpl(this, Notification.SET,
                    ResolutePackage.FAIL_EXPR__VAL, oldVal, newVal);
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
    public void setVal(StringLiteral newVal) {
        if (newVal != val) {
            NotificationChain msgs = null;
            if (val != null) {
                msgs = ((InternalEObject) val).eInverseRemove(this, EOPPOSITE_FEATURE_BASE
                        - ResolutePackage.FAIL_EXPR__VAL, null, msgs);
            }
            if (newVal != null) {
                msgs = ((InternalEObject) newVal).eInverseAdd(this, EOPPOSITE_FEATURE_BASE
                        - ResolutePackage.FAIL_EXPR__VAL, null, msgs);
            }
            msgs = basicSetVal(newVal, msgs);
            if (msgs != null) {
                msgs.dispatch();
            }
        } else if (eNotificationRequired()) {
            eNotify(new ENotificationImpl(this, Notification.SET, ResolutePackage.FAIL_EXPR__VAL,
                    newVal, newVal));
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
        case ResolutePackage.FAIL_EXPR__VAL:
            return basicSetVal(null, msgs);
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
        case ResolutePackage.FAIL_EXPR__VAL:
            return getVal();
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
        case ResolutePackage.FAIL_EXPR__VAL:
            setVal((StringLiteral) newValue);
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
        case ResolutePackage.FAIL_EXPR__VAL:
            setVal((StringLiteral) null);
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
        case ResolutePackage.FAIL_EXPR__VAL:
            return val != null;
        }
        return super.eIsSet(featureID);
    }

} // FailExprImpl