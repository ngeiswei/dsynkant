/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tone.cpp

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

#include "tone.hpp"

using namespace dsynkant;

Tone::Tone(const Voice& voice_,
           const Partial& partial1, const Partial& partial2,
           const Common& common)
	: voice(voice_), _partial1(partial1), _partial2(partial2),
	  _common(common) {}

void Tone::audio_process(float* left_out, float* right_out,
                         unsigned long sample_count) {
	// For now just write a square wave with amplitude +/- 0.1
	// TODO
}
