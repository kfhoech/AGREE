/*
Copyright (c) 2015, Rockwell Collins.
Developed with the sponsorship of Defense Advanced Research Projects Agency (DARPA).

Permission is hereby granted, free of charge, to any person obtaining a copy of this data, 
including any software or models in source or binary form, as well as any drawings, specifications, 
and documentation (collectively "the Data"), to deal in the Data without restriction, including
without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Data, and to permit persons to whom the Data is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Data.

THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS, SPONSORS, DEVELOPERS, CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE 
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE DATA OR THE USE OR OTHER DEALINGS IN THE DATA.
*/
package edu.uah.rsesc.aadlsimulator.agree.ui.commands;

import edu.uah.rsesc.aadlsimulator.agree.SimulationProperty;
import edu.uah.rsesc.aadlsimulator.agree.engine.AGREESimulationEngine;
import edu.uah.rsesc.aadlsimulator.ui.ext.Command;
import edu.uah.rsesc.aadlsimulator.ui.ext.CommandContext;

public class TogglePropertyEnablementCommand implements Command {
	@Override
	public boolean isAvailable(final CommandContext ctx) {
		return ctx.getSimulationEngine() instanceof AGREESimulationEngine && ctx.getBusinessObject() instanceof SimulationProperty;
	}

	@Override
	public String getLabel(final CommandContext ctx) {
		final boolean isPropertyEnabled = ctx.getSimulationEngineState().isPropertyEnabledForNextFrame(ctx.getBusinessObject());
		return isPropertyEnabled ? "Disable Property" : "Enable Property";
	}
	
	@Override
	public boolean isActivatable(final CommandContext ctx) {
		return true;
	}

	@Override
	public void activate(final CommandContext ctx) {
		final AGREESimulationEngine engine = (AGREESimulationEngine)ctx.getSimulationEngine();
		final boolean isPropertyEnabled = ctx.getSimulationEngineState().isPropertyEnabledForNextFrame(ctx.getBusinessObject());
		engine.setPropertyEnabled((SimulationProperty)ctx.getBusinessObject(), !isPropertyEnabled);	
	}
}
