/**************************************************************************
  Copyright (c) 2013-2016 Rockwell Collins and the University of
  Minnesota. Developed with the sponsorship of the Defense Advanced
  Research Projects Agency (DARPA).

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this data, including any software or models
  in source or binary form, as well as any drawings,
  specifications, and documentation (collectively "the Data"), to
  deal in the Data without restriction, including without
  limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Data, and to
  permit persons to whom the Data is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Data.

  THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, SPONSORS,
  DEVELOPERS, CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE DATA OR THE USE OR OTHER DEALINGS IN THE
  DATA.
 **************************************************************************/

/**************************************************************************

  ***AUTOGENERATED CODE: DO NOT MODIFY***

  This C file contains the implementations of the AADL primitives
  used by user-level declarations for thread Server.

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

#include "tb_Server.h"
#include <string.h>
#include <camkes.h>

/************************************************************************
 * periodic_dispatcher Declarations
 *
 ************************************************************************/

static bool tb_occurred_periodic_dispatcher;
static int64_t tb_time_periodic_dispatcher;

/************************************************************************
 * periodic_dispatcher_write_int64_t
 * Invoked from remote periodic dispatch thread.
 *
 * This function records the current time and triggers the active thread
 * dispatch from a periodic event.  Note that the periodic dispatch
 * thread is the *only* thread that triggers a dispatch, so we do not
 * mutex lock the function.
 *
 ************************************************************************/

bool periodic_dispatcher_write_int64_t(const int64_t * arg) {
    tb_occurred_periodic_dispatcher = true;
    tb_time_periodic_dispatcher = *arg;
    tb_dispatch_sem_post();

    return true;
}
  SMACCM_DATA__Camera_Bounding_Box_i tb_vm2self_var ;

/************************************************************************
 *  tb_Server_read_vm2self:
 * Invoked from local active thread.
 *
 * This is the function invoked by the active thread to read from a data port.
 *
 ************************************************************************/

bool tb_Server_read_vm2self(SMACCM_DATA__Camera_Bounding_Box_i * vm2self) {
    tb_server_vm2self_mut_lock();
    memcpy(vm2self, &tb_vm2self_var, sizeof(SMACCM_DATA__Camera_Bounding_Box_i));
    tb_server_vm2self_mut_unlock();
    return true;
}

/************************************************************************
 *  vm2self_write_SMACCM_DATA__Camera_Bounding_Box_i:
 * Invoked by remote RPC.
 *
 * This is the function that is invoked by an RPC to write to a data port.
 *
 ************************************************************************/

bool vm2self_write_SMACCM_DATA__Camera_Bounding_Box_i(const SMACCM_DATA__Camera_Bounding_Box_i * vm2self) {
    tb_server_vm2self_mut_lock();
    memcpy(&tb_vm2self_var, vm2self, sizeof(SMACCM_DATA__Camera_Bounding_Box_i));
    tb_server_vm2self_mut_unlock();
    return true;
}
 /************************************************************************
 *  tb_Server_write_self2encrypt:
 * Invoked from user code in the local thread.
 *
 * This is the function invoked by the local thread to make a
 * call to write to a remote data port.
 *
 ************************************************************************/

bool tb_Server_write_self2encrypt(const SMACCM_DATA__GIDL self2encrypt) {
    bool tb_result = true ; 

    tb_result &= self2encrypt_write_SMACCM_DATA__GIDL((tb_SMACCM_DATA__GIDL_container *) self2encrypt);

    return tb_result;
} /************************************************************************
 *
 * Static variables and queue management functions for event data port:
 *     decrypt2self
 *
 ************************************************************************/

static SMACCM_DATA__GIDL tb_queue_decrypt2self [1];
static bool tb_queue_full_decrypt2self  = false;
static uint32_t tb_queue_front_decrypt2self  = 0;
static uint32_t tb_queue_back_decrypt2self  = 0;

static bool tb_queue_is_full_decrypt2self() {
    return (tb_queue_front_decrypt2self == tb_queue_back_decrypt2self) && (tb_queue_full_decrypt2self);
}

static bool tb_queue_is_empty_decrypt2self() {
    return (tb_queue_front_decrypt2self == tb_queue_back_decrypt2self) && (!tb_queue_full_decrypt2self);
}

static bool tb_queue_read_decrypt2self(SMACCM_DATA__GIDL decrypt2self) {
    if (tb_queue_is_empty_decrypt2self()) {
        return false;
    } else {
        memcpy(decrypt2self, tb_queue_decrypt2self[tb_queue_front_decrypt2self], sizeof(SMACCM_DATA__GIDL));

        tb_queue_front_decrypt2self = (tb_queue_front_decrypt2self + 1) % 1;
        tb_queue_full_decrypt2self = false ;
        return true;
    }
}

static bool tb_queue_write_decrypt2self(const SMACCM_DATA__GIDL decrypt2self) {
    if (tb_queue_is_full_decrypt2self()) {
        return false;
    } else {
        memcpy(tb_queue_decrypt2self[tb_queue_back_decrypt2self], decrypt2self, sizeof(SMACCM_DATA__GIDL));

        tb_queue_back_decrypt2self = (tb_queue_back_decrypt2self + 1) % 1;
        if (tb_queue_back_decrypt2self == tb_queue_front_decrypt2self) {
            tb_queue_full_decrypt2self = true ;
        }
        return true;
    }
}

/************************************************************************
 *  decrypt2self_write_SMACCM_DATA__GIDL:
 * Invoked by: remote interface.
 *
 * This is the function invoked by a remote RPC to write to an active-thread
 * input event data port.  It queues the input message into a circular buffer.
 *
 ************************************************************************/

bool decrypt2self_write_SMACCM_DATA__GIDL(const tb_SMACCM_DATA__GIDL_container * arg) {
    bool result;
    tb_server_decrypt2self_mut_lock();
    result = tb_queue_write_decrypt2self((uint8_t *) arg);
    tb_server_decrypt2self_mut_unlock();
    return result;
}


/************************************************************************
 *  tb_Server_read_decrypt2self:
 * Invoked from local active thread.
 *
 * This is the function invoked by the active thread to read from the
 * input event data queue circular buffer.
 *
 ************************************************************************/

bool tb_Server_read_decrypt2self(SMACCM_DATA__GIDL arg) {
    bool result;
    tb_server_decrypt2self_mut_lock();
    result = tb_queue_read_decrypt2self(arg);
    tb_server_decrypt2self_mut_unlock();
    return result;
}
 /************************************************************************
 *  tb_Server_write_self2framing:
 * Invoked from user code in the local thread.
 *
 * This is the function invoked by the local thread to make a
 * call to write to a remote data port.
 *
 ************************************************************************/

bool tb_Server_write_self2framing(const SMACCM_DATA__GIDL self2framing) {
    bool tb_result = true ; 

    tb_result &= self2framing_write_SMACCM_DATA__GIDL((tb_SMACCM_DATA__GIDL_container *) self2framing);

    return tb_result;
} /************************************************************************
 *
 * Static variables and queue management functions for event data port:
 *     framing2self
 *
 ************************************************************************/

static SMACCM_DATA__GIDL tb_queue_framing2self [1];
static bool tb_queue_full_framing2self  = false;
static uint32_t tb_queue_front_framing2self  = 0;
static uint32_t tb_queue_back_framing2self  = 0;

static bool tb_queue_is_full_framing2self() {
    return (tb_queue_front_framing2self == tb_queue_back_framing2self) && (tb_queue_full_framing2self);
}

static bool tb_queue_is_empty_framing2self() {
    return (tb_queue_front_framing2self == tb_queue_back_framing2self) && (!tb_queue_full_framing2self);
}

static bool tb_queue_read_framing2self(SMACCM_DATA__GIDL framing2self) {
    if (tb_queue_is_empty_framing2self()) {
        return false;
    } else {
        memcpy(framing2self, tb_queue_framing2self[tb_queue_front_framing2self], sizeof(SMACCM_DATA__GIDL));

        tb_queue_front_framing2self = (tb_queue_front_framing2self + 1) % 1;
        tb_queue_full_framing2self = false ;
        return true;
    }
}

static bool tb_queue_write_framing2self(const SMACCM_DATA__GIDL framing2self) {
    if (tb_queue_is_full_framing2self()) {
        return false;
    } else {
        memcpy(tb_queue_framing2self[tb_queue_back_framing2self], framing2self, sizeof(SMACCM_DATA__GIDL));

        tb_queue_back_framing2self = (tb_queue_back_framing2self + 1) % 1;
        if (tb_queue_back_framing2self == tb_queue_front_framing2self) {
            tb_queue_full_framing2self = true ;
        }
        return true;
    }
}

/************************************************************************
 *  framing2self_write_SMACCM_DATA__GIDL:
 * Invoked by: remote interface.
 *
 * This is the function invoked by a remote RPC to write to an active-thread
 * input event data port.  It queues the input message into a circular buffer.
 *
 ************************************************************************/

bool framing2self_write_SMACCM_DATA__GIDL(const tb_SMACCM_DATA__GIDL_container * arg) {
    bool result;
    tb_server_framing2self_mut_lock();
    result = tb_queue_write_framing2self((uint8_t *) arg);
    tb_server_framing2self_mut_unlock();
    return result;
}


/************************************************************************
 *  tb_Server_read_framing2self:
 * Invoked from local active thread.
 *
 * This is the function invoked by the active thread to read from the
 * input event data queue circular buffer.
 *
 ************************************************************************/

bool tb_Server_read_framing2self(SMACCM_DATA__GIDL arg) {
    bool result;
    tb_server_framing2self_mut_lock();
    result = tb_queue_read_framing2self(arg);
    tb_server_framing2self_mut_unlock();
    return result;
}
 /************************************************************************
 *  tb_Server_write_self2vm_reboot:
 * Invoked from user code in the local thread.
 *
 * This is the function invoked by the local thread to make a
 * call to write to a remote data port.
 *
 ************************************************************************/

bool tb_Server_write_self2vm_reboot(const bool * self2vm_reboot) {
    bool tb_result = true ; 

    tb_result &= self2vm_reboot_write_bool(self2vm_reboot);

    return tb_result;
} 


/************************************************************************
 *  tb_entrypoint_Server_periodic_dispatcher:
 *
 * This is the function invoked by an active thread dispatcher to
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 *
 ************************************************************************/
void tb_entrypoint_Server_periodic_dispatcher(const int64_t * in_arg) {
    component_entry( in_arg);

}

/************************************************************************
 *  tb_entrypoint_Server_Server_initializer:
 *
 * This is the function invoked by an active thread dispatcher to
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 *
 ************************************************************************/
void tb_entrypoint_Server_Server_initializer(void) {
    component_init();

}

/************************************************************************
 *  tb_entrypoint_Server_decrypt2self:
 *
 * This is the function invoked by an active thread dispatcher to
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 *
 ************************************************************************/
void tb_entrypoint_Server_decrypt2self(const SMACCM_DATA__GIDL in_arg) {
}

/************************************************************************
 *  tb_entrypoint_Server_framing2self:
 *
 * This is the function invoked by an active thread dispatcher to
 * call to a user-defined entrypoint function.  It sets up the dispatch
 * context for the user-defined entrypoint, then calls it.
 *
 ************************************************************************/
void tb_entrypoint_Server_framing2self(const SMACCM_DATA__GIDL in_arg) {
}


/************************************************************************
 * int run(void)
 * Main active thread function.
 *
 ************************************************************************/

int run(void) {
    // thread initialization routines (if any)...
    tb_entrypoint_Server_Server_initializer();

    // Initial lock to await dispatch input.
    tb_dispatch_sem_wait();

    for(;;) {
        tb_dispatch_sem_wait();


        // Drain the queues
        if (tb_occurred_periodic_dispatcher) {
            tb_occurred_periodic_dispatcher = false;
            tb_entrypoint_Server_periodic_dispatcher(&tb_time_periodic_dispatcher);
        }
                
    }

    // Won't ever get here, but form must be followed
    return 0;
}
