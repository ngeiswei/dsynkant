/****************************************************************************
    
    DSSI wrapper for DSynkant

    dssidsynkant.cpp

    Copyleft (c) 2006 Nil Geisweiller
    
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

#include <cmath>

#include "dssidsynkant.hpp"

using namespace std;

static enum {
    LEFT_OUTPUT,
    RIGHT_OUTPUT
} enum_ports;


DSSIDSynkant::DSSIDSynkant(unsigned long frame_rate) {
}


void DSSIDSynkant::run_synth(unsigned long sample_count,
                             snd_seq_event_t* events,
                             unsigned long event_count) {
  
    LADSPA_Data* left_out = m_ports[LEFT_OUTPUT];
    LADSPA_Data* right_out = m_ports[RIGHT_OUTPUT];

    unsigned long e = 0; //current event in the loop
    unsigned long t = 0; //current tick
    unsigned long net = 0; //tick of the next event

    // handle any MIDI events that occur in this frame
    while(e < event_count) {
        if(events[e].time.tick == t) {
            switch(events[e].type) {
                //Note On, Off
            case SND_SEQ_EVENT_NOTEON :
                dsynkant.noteOn_process(0, events[e].data.note.note,
                                        events[e].data.note.velocity);
                break;
            case SND_SEQ_EVENT_NOTEOFF :
                dsynkant.noteOff_process(0, events[e].data.note.note);
                break;
                //Sysex
            case SND_SEQ_EVENT_SYSEX :
                dsynkant.sysex_process(events[e].data.ext.len,
                                       (unsigned char*) events[e].data.ext.ptr);
                break;
            default:
                break;
            }
            e++;
        }
        else {
            net = events[e].time.tick;
            dsynkant.audio_process(&left_out[t], &right_out[t], net - t);
            t = net;
        }
    }
    dsynkant.audio_process(&left_out[net], &right_out[net], sample_count - net);
}


int DSSIDSynkant::get_midi_controller_for_port(unsigned long port) {
    return DSSI_NONE;
}


const DSSI_Program_Descriptor* DSSIDSynkant::get_program(unsigned long index) {
    return NULL;
}

void DSSIDSynkant::select_program(unsigned long bank, unsigned long program) {
}

char* DSSIDSynkant::configure(const char* key, const char* value) {
    return NULL;
}

void initialise_2() __attribute__((constructor));


void initialise_2() {
    DSSIPortList ports;
  
    // control ports
    LADSPA_PortDescriptor c_desc = LADSPA_PORT_CONTROL | LADSPA_PORT_INPUT;
    LADSPA_PortRangeHintDescriptor r_desc = LADSPA_HINT_BOUNDED_BELOW | 
        LADSPA_HINT_BOUNDED_ABOVE;
    LADSPA_PortRangeHintDescriptor i_desc = LADSPA_HINT_BOUNDED_BELOW | 
        LADSPA_HINT_BOUNDED_ABOVE | LADSPA_HINT_INTEGER;
    LADSPA_PortRangeHintDescriptor t_desc = LADSPA_HINT_TOGGLED;
    LADSPA_PortRangeHintDescriptor d_middle = LADSPA_HINT_DEFAULT_MIDDLE;
    LADSPA_PortRangeHintDescriptor d_low = LADSPA_HINT_DEFAULT_MIDDLE;
    LADSPA_PortRangeHintDescriptor d_high = LADSPA_HINT_DEFAULT_MIDDLE;
    LADSPA_PortRangeHintDescriptor d_0 = LADSPA_HINT_DEFAULT_0;
  
    // audio output
    ports.add_port(LADSPA_PORT_AUDIO | LADSPA_PORT_OUTPUT, "Left output");
    ports.add_port(LADSPA_PORT_AUDIO | LADSPA_PORT_OUTPUT, "Right output");
  
    register_dssi<DSSIDSynkant>(2050, "DSynkant-DSSI", 0, "DSynkant DSSI plugin",
                                "Nil Geisweiller", "GPL", ports);
}

