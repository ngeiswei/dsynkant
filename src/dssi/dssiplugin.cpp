/****************************************************************************
    
    dssiplugin.cpp - a class and functions that should make it easier to
                     write DSSI plugins in C++
    
    Copyright (C) 2005  Lars Luthman <larsl@users.sourceforge.net>
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 01222-1307  USA

****************************************************************************/

#include <cassert>

#include "dssiplugin.hpp"


DSSIInitialiseFinalise g_dssi_init_fini_object;


void connect_port(LADSPA_Handle instance, unsigned long port, 
		  LADSPA_Data* data_location) {
  reinterpret_cast<DSSIPlugin*>(instance)->connect_port(port, data_location);
}


void activate(LADSPA_Handle instance) {
  reinterpret_cast<DSSIPlugin*>(instance)->activate();
}


void run(LADSPA_Handle instance, unsigned long sample_count) {
  reinterpret_cast<DSSIPlugin*>(instance)->run(sample_count);
}


void deactivate(LADSPA_Handle instance) {
  reinterpret_cast<DSSIPlugin*>(instance)->deactivate();
}


char* configure(LADSPA_Handle instance, const char* key, const char* value) {
  return reinterpret_cast<DSSIPlugin*>(instance)->configure(key, value);
}


void run_synth(LADSPA_Handle instance, unsigned long sample_count,
	       snd_seq_event_t* events, unsigned long event_count) {
  reinterpret_cast<DSSIPlugin*>(instance)->
    run_synth(sample_count, events, event_count);
}


int get_midi_controller_for_port(LADSPA_Handle instance, unsigned long port) {
  return reinterpret_cast<DSSIPlugin*>(instance)->
    get_midi_controller_for_port(port);
}


void select_program(LADSPA_Handle instance, unsigned long bank,
		    unsigned long program) {
  reinterpret_cast<DSSIPlugin*>(instance)->select_program(bank, program);
}


const DSSI_Program_Descriptor* get_program(LADSPA_Handle instance,
					   unsigned long index) {
  return reinterpret_cast<DSSIPlugin*>(instance)->get_program(index);
}
  

/* This needs to be declared extern C since the host will look for it by
   name, so it can't be mangled. */
extern "C" {
__attribute__ ((visibility("default"))) const DSSI_Descriptor* dssi_descriptor(unsigned long index) {
    if (index < get_dssi_descriptors().size())
      return &get_dssi_descriptors()[index];
    return NULL;
  }
}


// weak fallback implementations
void initialise() {
  
}


void finalise() {
  
} 


// singleton function that makes sure that the DSSI_Descriptor vector is
// properly initialised before it is used
vector<DSSI_Descriptor>& get_dssi_descriptors() {
  static vector<DSSI_Descriptor> descriptors;
  return descriptors;
}
