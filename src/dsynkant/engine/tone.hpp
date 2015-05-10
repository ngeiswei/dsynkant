/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tone.hpp

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

#ifndef __DSYNKANT_TONE_HPP
#define __DSYNKANT_TONE_HPP

#include "../set/partial.hpp"
#include "../set/common.hpp"

namespace dsynkant {

class Voice;

class Tone {

	///////////////////
	// Attributes    //
	///////////////////

private:
	const Partial& _partial1;
	const Partial& _partial2;
	const Common& _common;

public:
	// The voice to which it belongs
	const Voice& voice;

	/////////////////////////////////
	// Constructors/descructors    //
	/////////////////////////////////

	Tone(const Voice& voice,
	     const Partial& partial1, const Partial& partial2,
	     const Common& common);

	////////////////
	// Methods    //
	////////////////

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
