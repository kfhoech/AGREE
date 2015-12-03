/**************************************************************************
  Copyright (c) 2013, 2014, 2015 Rockwell Collins and the University of Minnesota.
  Developed with the sponsorship of the Defense Advanced Research Projects Agency (DARPA).

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

 **************************************************************************/


/**************************************************************************

   File: /home/john/workspace/smaccm/models/SmaccmPhaseIII/components/dispatch_periodic/src/smaccm_dispatch_periodic.c
   Created on: 2015/12/03 11:29:22
   using Dulcimer AADL system build tool suite 

   ***AUTOGENERATED CODE: DO NOT MODIFY***

  This .c file contains the CAmkES periodic dispatcher component definition.

 **************************************************************************/
#include <string.h>
#include <smaccm_top_i_types.h>
#include <dispatch_periodic.h>


// prototypes for clock functions
void clock_init();
void clock_set_interval_in_ms(uint32_t interval);
void clock_start_timer(void);
void clock_irq_callback(void);
uint64_t clock_get_time();

// Declarations for managing periodic thread dispatch
const uint32_t smaccm_tick_interval = 100;
const uint32_t smaccm_hyperperiod_subdivisions = 1;
uint32_t smaccm_calendar_counter = 0;
uint32_t smaccm_calendar_ticks = 0;


void smaccm_thread_calendar() {
	if ((smaccm_calendar_counter % (100 / smaccm_tick_interval)) == 0) {
		// MWW: modification of time type to match Ivory/Tower (CAmkES time server uses uint64_t)
		int64_t the_time = (int64_t)clock_get_time();
		PixhawkProxy_periodic_dispatcher_write_int64_t(&the_time); 
	}if ((smaccm_calendar_counter % (100 / smaccm_tick_interval)) == 0) {
		// MWW: modification of time type to match Ivory/Tower (CAmkES time server uses uint64_t)
		int64_t the_time = (int64_t)clock_get_time();
		Input_periodic_dispatcher_write_int64_t(&the_time); 
	}

	smaccm_calendar_counter = (smaccm_calendar_counter + 1) % smaccm_hyperperiod_subdivisions; 
	smaccm_calendar_ticks++; 
}
 

// no op under the new time server scheme.
void clock_init() { }

/* Set interrupt interval, in milliseconds. */
void clock_set_interval_in_ms(uint32_t interval)
{
	timer_periodic(0, ((uint64_t)interval)*NS_IN_MS);
}

// no op under the new time server scheme
void clock_start_timer(void) { }

// defer to time server
uint64_t clock_get_time()
{
	return (timer_time() / NS_IN_MS);
}

void timer_complete_callback() {
	smaccm_thread_calendar(); 
}

int run(void)
{
	clock_init();
	clock_set_interval_in_ms(100);

	clock_start_timer();

	return 0;
}

/**************************************************************************
  End of autogenerated file: /home/john/workspace/smaccm/models/SmaccmPhaseIII/components/dispatch_periodic/src/smaccm_dispatch_periodic.c
 **************************************************************************/

