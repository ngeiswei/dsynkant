/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    dsynkant.hpp

    Copyleft (c) 2006-2007 Nil Geisweiller
 
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

#ifndef __DSYNKANT_DSYNKANT_HPP
#define __DSYNKANT_DSYNKANT_HPP

#include "set/set.hpp"
#include "set/patch.hpp"
#include "engine/engine.hpp"

// Set 1 if you want to print debug messages, 0 otherwise
#define ENABLE_PRINT_DEBUG 1

#if ENABLE_PRINT_DEBUG
#define dbg_printf(f, varargs...) printf(f, ##varargs)
#else
#define dbg_printf(f, varargs...)
#endif

namespace dsynkant {

#define COMMAND_DUMP_PATCH 0x12

class DSynkant {
private:
	Set _set; // A Set is a set of banks, themselves containing patches
	Patch _workPatch; // Patch that the engine works on
	Engine _engine; // Engine of the DSynkant
  
public:
	DSynkant();
	~DSynkant();

	// Assumptions:
	//
	// 1. The parameters do not change during audio processing
	//
	// 2. All processing is added to the buffers
	void audio_process(float* left_out, float* right_out,
	                   unsigned long sample_count);
	void noteOn_process(unsigned char channel,
	                    unsigned char pitch,
	                    unsigned char velocity);
	void noteOff_process(unsigned char channel, unsigned char pitch);
	void sysex_process(unsigned length, unsigned char* data);

	//print method
	void print();
};

} // ~namespace dsynkant

#endif
