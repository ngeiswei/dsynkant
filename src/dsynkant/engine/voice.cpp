/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    voice.cpp

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

#include "voice.hpp"

using namespace dsynkant;

Voice::Voice(const Patch& patch,
             unsigned char pitch_, unsigned char velocity_) :
	pitch(pitch_), velocity(velocity_), noteOn(true),
	_upperTone(*this,
	           patch.upperPartial1, patch.upperPartial2, patch.upperCommon),
	_lowerTone(*this,
	           patch.lowerPartial1, patch.lowerPartial2, patch.lowerCommon) {}

void Voice::setNoteOff() {
	noteOn = false;
}

void Voice::audio_process(float* left_out, float* right_out,
                          unsigned long sample_count) {
	// For now it just adds up the upper and the lower tones
	_upperTone.audio_process(left_out, right_out, sample_count);
	_lowerTone.audio_process(left_out, right_out, sample_count);
}
