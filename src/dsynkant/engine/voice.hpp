/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    voice.hpp

    Copyleft (c) 2015 Nil Geisweiller
 
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

#ifndef __DSYNKANT_VOICE_HPP
#define __DSYNKANT_VOICE_HPP

#include "tone.hpp"
#include "../set/patch.hpp"

namespace dsynkant {

/**
 * Holds information about the state of a voice (note, sample freq,
 * volume, sample offset, etc)
 */

class Voice {

	///////////////////
	// Attributes    //
	///////////////////

private:
	Tone _upperTone;
	Tone _lowerTone;

public:
	unsigned char pitch;
	unsigned char velocity;
	bool noteOn;
	static const unsigned char C4_pitch = 64;

	/////////////////////////////////
	// Constructors/descructors    //
	/////////////////////////////////

	Voice(const Patch& patch, unsigned char pitch, unsigned char velocity);

	////////////////
	// Methods    //
	////////////////

	// Modifiers
	void setNoteOff();

	// Assumptions:
	//
	// 1. The parameters do not change during audio processing
	//
	// 2. All processing is added to the buffers
	void audio_process(float* left_out, float* right_out,
	                   unsigned long sample_count);
};

} // ~namespace dsynkant

#endif
