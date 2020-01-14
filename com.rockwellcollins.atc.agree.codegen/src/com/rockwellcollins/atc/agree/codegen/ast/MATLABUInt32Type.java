package com.rockwellcollins.atc.agree.codegen.ast;

import com.rockwellcollins.atc.agree.codegen.visitors.MATLABTypeVisitor;

public class MATLABUInt32Type extends MATLABType {

	public final int defaultValue = 0;
	public final String name = "uint32";

	@Override
	public <T> T accept(MATLABTypeVisitor<T> visitor) {
		return visitor.visit(this);
	}

	@Override
	public String getValueStr() {
		return Integer.toString(defaultValue);
	}

	@Override
	public String toString() {
		return name;
	}

}
