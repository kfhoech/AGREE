package com.rockwellcollins.atc.agree.codegen.visitors;

import com.rockwellcollins.atc.agree.codegen.preferences.PreferenceConstants;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABBoolType;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABBusType;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABDoubleType;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABInt16Type;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABInt32Type;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABInt8Type;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABSingleType;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABType;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABUInt16Type;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABUInt32Type;
import com.rockwellcollins.atc.agree.codegen.ast.MATLABUInt8Type;
import com.rockwellcollins.atc.agree.codegen.translation.LustreToMATLABTranslator;

import jkind.lustre.ArrayType;
import jkind.lustre.EnumType;
import jkind.lustre.NamedType;
import jkind.lustre.RecordType;
import jkind.lustre.SubrangeIntType;
import jkind.lustre.TupleType;
import jkind.lustre.visitors.TypeVisitor;

public class LustreToMATLABTypeVisitor implements TypeVisitor<MATLABType> {
	
	@Override
	public MATLABType visit(ArrayType e) {
		throw new IllegalArgumentException(); 
	}

	@Override
	public MATLABType visit(NamedType e) {
		if(e.name.equals("bool") || e.name.equals("Base_Types__Boolean"))
			return new MATLABBoolType();
		else if(e.name.equals("Base_Types__Unsigned")){
			switch (LustreToMATLABTranslator.intTypeStr) {
			case PreferenceConstants.INT_UINT8:
				return new MATLABUInt8Type();
			case PreferenceConstants.INT_UINT16:
				return new MATLABUInt16Type();
			case PreferenceConstants.INT_UINT32:
				return new MATLABUInt32Type();   		
			default:
				throw new IllegalArgumentException("Base_Types__Unsigned mismatch with "+LustreToMATLABTranslator.intTypeStr);
			}
		}
		else if(e.name.equals("Base_Types__Integer")){
			switch (LustreToMATLABTranslator.intTypeStr) {
			case PreferenceConstants.INT_INT8:
				return new MATLABInt8Type();
			case PreferenceConstants.INT_INT16:
				return new MATLABInt16Type();
			case PreferenceConstants.INT_INT32:
				return new MATLABInt32Type();    		
			default:
				throw new IllegalArgumentException("Base_Types__Integer mismatch with "+LustreToMATLABTranslator.intTypeStr);
			}
		}
		else if(e.name.equals("int")){
			switch (LustreToMATLABTranslator.intTypeStr) {
			case PreferenceConstants.INT_INT8:
				return new MATLABInt8Type();
			case PreferenceConstants.INT_UINT8:
				return new MATLABUInt8Type();
			case PreferenceConstants.INT_INT16:
				return new MATLABInt16Type();
			case PreferenceConstants.INT_UINT16:
				return new MATLABUInt16Type();
			case PreferenceConstants.INT_INT32:
				return new MATLABInt32Type();
			case PreferenceConstants.INT_UINT32:
				return new MATLABUInt32Type();   		
			default:
				throw new IllegalArgumentException("Unknown int type: "+LustreToMATLABTranslator.intTypeStr);
			}
		}
		else if(e.name.equals("real") || e.name.equals("Base_Types__Float")){
			switch (LustreToMATLABTranslator.realTypeStr) {
			case PreferenceConstants.REAL_SINGLE:
				return new MATLABSingleType();
			case PreferenceConstants.REAL_DOUBLE:
				return new MATLABDoubleType();    		
			default:
				throw new IllegalArgumentException("Unknown real type: "+LustreToMATLABTranslator.realTypeStr);
			}
		}
		else if(e.name.equals("Base_Types__Unsigned_32")){
			return new MATLABUInt32Type(); 
		}
		else if(e.name.equals("Base_Types__Unsigned_16")){
			return new MATLABUInt16Type(); 
		}
		else if(e.name.equals("Base_Types__Unsigned_8")){
			return new MATLABUInt8Type(); 
		}
		else if(e.name.equals("Base_Types__Integer_32")){
			return new MATLABInt32Type(); 
		}
		else if(e.name.equals("Base_Types__Integer_16")){
			return new MATLABInt16Type(); 
		}
		else if(e.name.equals("Base_Types__Integer_8")){
			return new MATLABInt8Type(); 
		}
		else if(e.name.equals("Base_Types__Float_32")){
			return new MATLABSingleType(); 
		}
		else if(e.name.equals("Base_Types__Float_64")){
			return new MATLABDoubleType(); 
		}
		else
			return new MATLABBusType(e.name);
	}
	
	@Override
	public MATLABType visit(EnumType e) {
		throw new IllegalArgumentException(); 
	}

	@Override
	public MATLABType visit(RecordType e) {
		return new MATLABBusType(e.id);
	}

	@Override
	public MATLABType visit(TupleType e) {
		throw new IllegalArgumentException(); 
	}
	
	@Override
	public MATLABType visit(SubrangeIntType e) {
		throw new IllegalArgumentException();
	}
}
