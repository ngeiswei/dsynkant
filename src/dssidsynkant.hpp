/****************************************************************************
    
    DSSI wrapper for DSynkant

    dssidsynkant.hpp

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

#ifndef __DSSIDSYNKANT_HPP
#define __DSSIDSYNKANT_HPP

#include "dssiplugin.hpp"
#include "dsynkant/dsynkant.hpp"

class DSynkant;

class DSSIDSynkant : public DSSIPlugin {
public:
  DSynkant* dsynkant;

  DSSIDSynkant(unsigned long frame_rate);
  
  void run_synth(unsigned long sample_count, snd_seq_event_t* events,
		 unsigned long event_count);
  int get_midi_controller_for_port(unsigned long port);
  
  const DSSI_Program_Descriptor* get_program(unsigned long index);
  void select_program(unsigned long bank, unsigned long program);
  
  char* configure(const char* key, const char* value);
  
protected:
  
  
  unsigned long m_frame_rate;
  unsigned long m_last_frame;
  
  LADSPA_Data m_velocity;
  LADSPA_Data m_pitch;
  unsigned char m_note;
  bool m_note_is_on;
    
  DSSI_Program_Descriptor m_prog;
  
  LADSPA_Data m_pitchbend;
};


#endif
