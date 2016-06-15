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

   File: /home/john/git/smaccm/models/SmaccmPhaseIIIV2/components/Encrypt/src/smaccm_Encrypt.c
   Created on: 2016/06/15 16:38:08
   using Dulcimer AADL system build tool suite 

   ***AUTOGENERATED CODE: DO NOT MODIFY***

  This C file contains the implementations of the AADL primitives
  used by user-level declarations for thread Encrypt.   

  The user code runs in terms of "dispatchers", which cause 
  dispatch user-level handlers to execute.  These handlers can 
  communicate using the standard AADL primitives, which are mapped
  to C functions.

  The send/receive handlers are not thread safe in CAmkES; it is 
  assumed that this is handled by the CAmkES sequentialized access 
  to the dispatch handler.  There is only one dispatch interface 
  for the component containing all of the dispatch points.

  They are thread safe for eChronos.

  The read/write handlers are thread safe because the writer comes 
  through a dispatch interface but the reader is "local" on a dispatch
  interface and so contention may occur.


 **************************************************************************/
#include <smaccm_Encrypt.h>
#include <string.h>
#include <Encrypt.h>

///////////////////////////////////////////////////////////////////////////
//
// Local prototypes for AADL dispatchers
//
///////////////////////////////////////////////////////////////////////////
static void 
smaccm_Encrypt_periodic_dispatcher_dispatcher(int64_t * periodic_dispatcher); 
static void 
smaccm_Encrypt_Encrypt_initializer_dispatcher(int64_t * Encrypt_initializer); 
static void 
smaccm_Encrypt_get_gidl_dispatcher(SMACCM_DATA__Array_U8_80 get_gidl); 
static void 
smaccm_Encrypt_recv_response_dispatcher(bool * recv_response); 
 
 



/************************************************************************
 * 
 * Static variables and queue management functions for port:
 * 	get_gidl
 * 
 ************************************************************************/

static SMACCM_DATA__Array_U8_80 smaccm_queue_get_gidl [1];
static bool smaccm_queue_full_get_gidl  = false;
static uint32_t smaccm_queue_front_get_gidl  = 0;
static uint32_t smaccm_queue_back_get_gidl  = 0;

bool smaccm_queue_is_full_get_gidl() {
	return (smaccm_queue_front_get_gidl == smaccm_queue_back_get_gidl) && (smaccm_queue_full_get_gidl);
}

bool smaccm_queue_is_empty_get_gidl() {
	return (smaccm_queue_front_get_gidl == smaccm_queue_back_get_gidl) && (!smaccm_queue_full_get_gidl); 
}

bool smaccm_queue_read_get_gidl(SMACCM_DATA__Array_U8_80 get_gidl) {
	if (smaccm_queue_is_empty_get_gidl()) {
		return false;
	} else {
		memcpy(get_gidl, smaccm_queue_get_gidl[smaccm_queue_back_get_gidl], sizeof(SMACCM_DATA__Array_U8_80));

		smaccm_queue_back_get_gidl = (smaccm_queue_back_get_gidl + 1) % 1; 
		smaccm_queue_full_get_gidl = false ; 
		return true;
	}
}

bool smaccm_queue_write_get_gidl(const SMACCM_DATA__Array_U8_80 get_gidl) {
	if (smaccm_queue_is_full_get_gidl()) {
		return false;
	} else {
		memcpy(smaccm_queue_get_gidl[smaccm_queue_front_get_gidl], get_gidl, sizeof(SMACCM_DATA__Array_U8_80));

		smaccm_queue_front_get_gidl = (smaccm_queue_front_get_gidl + 1) % 1; 		
		if (smaccm_queue_back_get_gidl == smaccm_queue_front_get_gidl) { 
			smaccm_queue_full_get_gidl = true ; 
		}
		return true;
	}
}

/************************************************************************
 *  get_gidl_write_SMACCM_DATA__Array_U8_80: 
 * Invoked by: remote interface.
 * 
 * This is the function invoked by a remote RPC to write to an active-thread
 * input event data port.  It queues the input message into a circular buffer.
 * 
 ************************************************************************/

bool get_gidl_write_SMACCM_DATA__Array_U8_80(const smaccm_SMACCM_DATA__Array_U8_80_container * arg) {
	bool result;
	smaccm_encrypt_get_gidl_mut_lock(); 
	result = smaccm_queue_write_get_gidl((uint8_t *) arg);
	smaccm_encrypt_get_gidl_mut_unlock(); 
	return result;
}


/************************************************************************
 *  Encrypt_read_get_gidl: 
 * Invoked from local active thread.
 * 
 * This is the function invoked by the active thread to read from the 
 * input event data queue circular buffer.
 * 
 ************************************************************************/

bool Encrypt_read_get_gidl(SMACCM_DATA__Array_U8_80 arg) {
	bool result; 
	smaccm_encrypt_get_gidl_mut_lock(); 
	result = smaccm_queue_read_get_gidl(arg);
	smaccm_encrypt_get_gidl_mut_unlock(); 
	return result;
}


/************************************************************************
 * 
 * Static variables and queue management functions for port:
 * 	recv_response
 * 
 ************************************************************************/

static bool smaccm_queue_recv_response [1];
static bool smaccm_queue_full_recv_response  = false;
static uint32_t smaccm_queue_front_recv_response  = 0;
static uint32_t smaccm_queue_back_recv_response  = 0;

bool smaccm_queue_is_full_recv_response() {
	return (smaccm_queue_front_recv_response == smaccm_queue_back_recv_response) && (smaccm_queue_full_recv_response);
}

bool smaccm_queue_is_empty_recv_response() {
	return (smaccm_queue_front_recv_response == smaccm_queue_back_recv_response) && (!smaccm_queue_full_recv_response); 
}

bool smaccm_queue_read_recv_response(bool * recv_response) {
	if (smaccm_queue_is_empty_recv_response()) {
		return false;
	} else {
		*recv_response = smaccm_queue_recv_response[smaccm_queue_back_recv_response] ;

		smaccm_queue_back_recv_response = (smaccm_queue_back_recv_response + 1) % 1; 
		smaccm_queue_full_recv_response = false ; 
		return true;
	}
}

bool smaccm_queue_write_recv_response(const bool * recv_response) {
	if (smaccm_queue_is_full_recv_response()) {
		return false;
	} else {
		smaccm_queue_recv_response[smaccm_queue_front_recv_response] = *recv_response ;

		smaccm_queue_front_recv_response = (smaccm_queue_front_recv_response + 1) % 1; 		
		if (smaccm_queue_back_recv_response == smaccm_queue_front_recv_response) { 
			smaccm_queue_full_recv_response = true ; 
		}
		return true;
	}
}

/************************************************************************
 *  recv_response_write_bool: 
 * Invoked by: remote interface.
 * 
 * This is the function invoked by a remote RPC to write to an active-thread
 * input event data port.  It queues the input message into a circular buffer.
 * 
 ************************************************************************/

bool recv_response_write_bool(const bool * arg) {
	bool result;
	smaccm_encrypt_recv_response_mut_lock(); 
	result = smaccm_queue_write_recv_response( arg);
	smaccm_encrypt_recv_response_mut_unlock(); 
	return result;
}


/************************************************************************
 *  Encrypt_read_recv_response: 
 * Invoked from local active thread.
 * 
 * This is the function invoked by the active thread to read from the 
 * input event data queue circular buffer.
 * 
 ************************************************************************/

bool Encrypt_read_recv_response(bool * arg) {
	bool result; 
	smaccm_encrypt_recv_response_mut_lock(); 
	result = smaccm_queue_read_recv_response(arg);
	smaccm_encrypt_recv_response_mut_unlock(); 
	return result;
}



static SMACCM_DATA__UartPacket_i * smaccm_tmp_array_send_packet; 
static uint32_t * smaccm_tmp_used_send_packet;
static uint32_t smaccm_max_tmp_array_send_packet; 	


/************************************************************************
 * periodic_dispatcher Declarations
 * 
 ************************************************************************/

static bool smaccm_occurred_periodic_dispatcher;
static int64_t smaccm_time_periodic_dispatcher;

/************************************************************************
 * Encrypt_periodic_dispatcher_write_int64_t
 * Invoked from remote periodic dispatch thread.
 * 
 * This function records the current time and triggers the active thread 
 * dispatch from a periodic event.
 * 
 ************************************************************************/

bool Encrypt_periodic_dispatcher_write_int64_t(const int64_t * arg) {
	smaccm_occurred_periodic_dispatcher = true;
	smaccm_time_periodic_dispatcher = *arg;
	smaccm_dispatch_sem_post();

	return true;
}

 
 
 

/************************************************************************
 *  dispatch_dispatch_periodic_dispatcher: 
 * Invoked by remote RPC (or, for active thread, local dispatcher).
 * 
 * This is the function invoked by an active thread dispatcher to 
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 * 
 ************************************************************************/

void dispatch_dispatch_periodic_dispatcher(
  const int64_t * in_arg ,
  smaccm_Encrypt_periodic_dispatcher_struct *out_arg) {
	smaccm_max_tmp_array_send_packet = 0;

	component_entry( in_arg); 

}	


/************************************************************************
 *  dispatch_dispatch_Encrypt_initializer: 
 * Invoked by remote RPC (or, for active thread, local dispatcher).
 * 
 * This is the function invoked by an active thread dispatcher to 
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 * 
 ************************************************************************/

void dispatch_dispatch_Encrypt_initializer(
  const int64_t * in_arg ,
  smaccm_Encrypt_Encrypt_initializer_struct *out_arg) {
	smaccm_max_tmp_array_send_packet = 0;

	component_init( in_arg); 

}	


/************************************************************************
 *  dispatch_dispatch_get_gidl: 
 * Invoked by remote RPC (or, for active thread, local dispatcher).
 * 
 * This is the function invoked by an active thread dispatcher to 
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 * 
 ************************************************************************/

void dispatch_dispatch_get_gidl(
  const smaccm_SMACCM_DATA__Array_U8_80_container * in_arg ,
  smaccm_Encrypt_get_gidl_struct *out_arg) {
	smaccm_max_tmp_array_send_packet = 0;

}	


/************************************************************************
 *  dispatch_dispatch_recv_response: 
 * Invoked by remote RPC (or, for active thread, local dispatcher).
 * 
 * This is the function invoked by an active thread dispatcher to 
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 * 
 ************************************************************************/

void dispatch_dispatch_recv_response(
  const bool * in_arg ,
  smaccm_Encrypt_recv_response_struct *out_arg) {
	smaccm_max_tmp_array_send_packet = 0;

}	



/************************************************************************
 * Encrypt_write_send_packet 
 * Invoked from local active or passive thread.
 * 
 * This is the comm function invoked by a user-level thread to send a message 
 * to another thread.  It enqueues the request to be sent when the user thread
 * completes execution.
 * 
 ************************************************************************/

bool Encrypt_write_send_packet(const SMACCM_DATA__UartPacket_i * send_packet) {
	if (smaccm_max_tmp_array_send_packet > 0 && 
		 *smaccm_tmp_used_send_packet < smaccm_max_tmp_array_send_packet) {
		memcpy(&smaccm_tmp_array_send_packet[*smaccm_tmp_used_send_packet], send_packet, sizeof(SMACCM_DATA__UartPacket_i));

		(*smaccm_tmp_used_send_packet)++;
		return true;
	} else {
		return false;
	}
}


/************************************************************************
 * 
smaccm_Encrypt_periodic_dispatcher_dispatcher
 * Invoked from local active thread.
 * 
 * This is the dispatcher function invoked to respond to an incoming thread 
 * stimulus: an ISR, a periodic dispatch, or a queued event.
 * 
 ******************************************************************************/
static smaccm_Encrypt_periodic_dispatcher_struct smaccm_Encrypt_periodic_dispatcher_arg;

void 
smaccm_Encrypt_periodic_dispatcher_dispatcher(int64_t * periodic_dispatcher) {

	 
	// make the call: 
	dispatch_dispatch_periodic_dispatcher( periodic_dispatcher,
  &smaccm_Encrypt_periodic_dispatcher_arg	
		); 
	 

}
/************************************************************************
 * 
smaccm_Encrypt_Encrypt_initializer_dispatcher
 * Invoked from local active thread.
 * 
 * This is the dispatcher function invoked to respond to an incoming thread 
 * stimulus: an ISR, a periodic dispatch, or a queued event.
 * 
 ******************************************************************************/
static smaccm_Encrypt_Encrypt_initializer_struct smaccm_Encrypt_Encrypt_initializer_arg;

void 
smaccm_Encrypt_Encrypt_initializer_dispatcher(int64_t * Encrypt_initializer) {

	 
	// make the call: 
	dispatch_dispatch_Encrypt_initializer( Encrypt_initializer,
  &smaccm_Encrypt_Encrypt_initializer_arg	
		); 
	 

}
/************************************************************************
 * 
smaccm_Encrypt_get_gidl_dispatcher
 * Invoked from local active thread.
 * 
 * This is the dispatcher function invoked to respond to an incoming thread 
 * stimulus: an ISR, a periodic dispatch, or a queued event.
 * 
 ******************************************************************************/
static smaccm_Encrypt_get_gidl_struct smaccm_Encrypt_get_gidl_arg;

void 
smaccm_Encrypt_get_gidl_dispatcher(SMACCM_DATA__Array_U8_80 get_gidl) {

	 
	// make the call: 
	dispatch_dispatch_get_gidl((smaccm_SMACCM_DATA__Array_U8_80_container *) get_gidl,
  &smaccm_Encrypt_get_gidl_arg	
		); 
	 

}
/************************************************************************
 * 
smaccm_Encrypt_recv_response_dispatcher
 * Invoked from local active thread.
 * 
 * This is the dispatcher function invoked to respond to an incoming thread 
 * stimulus: an ISR, a periodic dispatch, or a queued event.
 * 
 ******************************************************************************/
static smaccm_Encrypt_recv_response_struct smaccm_Encrypt_recv_response_arg;

void 
smaccm_Encrypt_recv_response_dispatcher(bool * recv_response) {

	 
	// make the call: 
	dispatch_dispatch_recv_response( recv_response,
  &smaccm_Encrypt_recv_response_arg	
		); 
	 

}

 
/************************************************************************
 * run
 * Main active thread function.
 * 
 ************************************************************************/

int run() {
	// port initialization routines (if any)... 

	// thread initialization routines (if any)...
	  int64_t dummy_time = 0;

	  smaccm_Encrypt_Encrypt_initializer_dispatcher(&dummy_time);
	// register interrupt handlers (if any)...
	    

	// initial lock to await dispatch input.
	smaccm_dispatch_sem_wait();

	for(;;) {
		smaccm_dispatch_sem_wait();


		// drain the queues 
		if (smaccm_occurred_periodic_dispatcher) {
			smaccm_occurred_periodic_dispatcher = false;

			smaccm_Encrypt_periodic_dispatcher_dispatcher(&smaccm_time_periodic_dispatcher);
		}

		while (!smaccm_queue_is_empty_get_gidl()) {
			SMACCM_DATA__Array_U8_80 get_gidl ;
			smaccm_queue_read_get_gidl(get_gidl);

			smaccm_Encrypt_get_gidl_dispatcher(get_gidl); 
		}

		while (!smaccm_queue_is_empty_recv_response()) {
			bool recv_response ;
			smaccm_queue_read_recv_response(&recv_response);

			smaccm_Encrypt_recv_response_dispatcher(&recv_response); 
		}


	}
	// won't ever get here, but form must be followed
	return 0;
}




/**************************************************************************
  End of autogenerated file: /home/john/git/smaccm/models/SmaccmPhaseIIIV2/components/Encrypt/src/smaccm_Encrypt.c
 **************************************************************************/
