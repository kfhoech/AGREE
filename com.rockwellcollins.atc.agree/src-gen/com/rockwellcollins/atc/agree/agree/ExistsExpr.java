/**
 */
package com.rockwellcollins.atc.agree.agree;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Exists Expr</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link com.rockwellcollins.atc.agree.agree.ExistsExpr#getBinding <em>Binding</em>}</li>
 *   <li>{@link com.rockwellcollins.atc.agree.agree.ExistsExpr#getArray <em>Array</em>}</li>
 *   <li>{@link com.rockwellcollins.atc.agree.agree.ExistsExpr#getExpr <em>Expr</em>}</li>
 * </ul>
 *
 * @see com.rockwellcollins.atc.agree.agree.AgreePackage#getExistsExpr()
 * @model
 * @generated
 */
public interface ExistsExpr extends Expr
{
  /**
   * Returns the value of the '<em><b>Binding</b></em>' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the value of the '<em>Binding</em>' containment reference.
   * @see #setBinding(NamedID)
   * @see com.rockwellcollins.atc.agree.agree.AgreePackage#getExistsExpr_Binding()
   * @model containment="true"
   * @generated
   */
  NamedID getBinding();

  /**
   * Sets the value of the '{@link com.rockwellcollins.atc.agree.agree.ExistsExpr#getBinding <em>Binding</em>}' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @param value the new value of the '<em>Binding</em>' containment reference.
   * @see #getBinding()
   * @generated
   */
  void setBinding(NamedID value);

  /**
   * Returns the value of the '<em><b>Array</b></em>' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the value of the '<em>Array</em>' containment reference.
   * @see #setArray(Expr)
   * @see com.rockwellcollins.atc.agree.agree.AgreePackage#getExistsExpr_Array()
   * @model containment="true"
   * @generated
   */
  Expr getArray();

  /**
   * Sets the value of the '{@link com.rockwellcollins.atc.agree.agree.ExistsExpr#getArray <em>Array</em>}' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @param value the new value of the '<em>Array</em>' containment reference.
   * @see #getArray()
   * @generated
   */
  void setArray(Expr value);

  /**
   * Returns the value of the '<em><b>Expr</b></em>' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the value of the '<em>Expr</em>' containment reference.
   * @see #setExpr(Expr)
   * @see com.rockwellcollins.atc.agree.agree.AgreePackage#getExistsExpr_Expr()
   * @model containment="true"
   * @generated
   */
  Expr getExpr();

  /**
   * Sets the value of the '{@link com.rockwellcollins.atc.agree.agree.ExistsExpr#getExpr <em>Expr</em>}' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @param value the new value of the '<em>Expr</em>' containment reference.
   * @see #getExpr()
   * @generated
   */
  void setExpr(Expr value);

} // ExistsExpr
