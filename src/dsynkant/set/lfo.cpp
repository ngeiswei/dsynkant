/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    lfo.cpp

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

#include <iostream>

#include "lfo.hpp"
#include "../commondef/commondef.hpp"
#include <stdio.h>

//Constructor destructor
LFO::LFO(unsigned char rate, Sync sync) {
	_waveform = LFOWaveform::TRI;
	_rate = rate;
	_delayTime = 0;
	_sync = sync;
}

LFO::~LFO() {
}

//affect methods
void LFO::setWaveform(LFOWaveform wf) {
	_waveform = wf;
}
void LFO::setRate(unsigned char r) {
	_rate = r;
}
void LFO::setDelayTime(unsigned char dt) {
	_delayTime = dt;
}
void LFO::setSync(Sync s) {
	_sync = s;
}

//access methods
LFOWaveform LFO::getWaveform() const {
	return _waveform;
}
unsigned char LFO::getRate() const {
	return _rate;
}
unsigned char LFO::getDelayTime() const {
	return _delayTime;
}
Sync LFO::getSync() const {
	return _sync;
}

void LFO::dump(Address& a, unsigned length, const unsigned char* data) {
	Address cura;
	unsigned index = 0;
	if(length > index && a == cura) {
		_waveform = (LFOWaveform)data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_rate = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_delayTime = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_sync = (Sync)data[index];
		++a;
	}
}

std::string LFO::LFOWaveformStr(LFOWaveform wf) const {
	switch(wf) {
	case LFOWaveform::TRI : return TRI_Str; break;
	case LFOWaveform::SAW : return SAW_Str; break;
	case LFOWaveform::SQU : return SQU_Str; break;
	case LFOWaveform::RND : return RND_Str; break;
	default :
		std::cerr << "LFO::LFOWaveformStr error : impossible case";
		return std::string();
	}
}
std::string LFO::LFOWaveformStr() const {
	return LFOWaveformStr(_waveform);
}
std::string LFO::LFOWaveformShortStr(LFOWaveform wf) const {
	switch(wf) {
	case LFOWaveform::TRI : return TRI_Short_Str; break;
	case LFOWaveform::SAW : return SAW_Short_Str; break;
	case LFOWaveform::SQU : return SQU_Short_Str; break;
	case LFOWaveform::RND : return RND_Short_Str; break;
	default :
		std::cerr << "LFO::LFOWaveformStr error : impossible case";
		return std::string();
	}
}
std::string LFO::LFOWaveformShortStr() const {
	return LFOWaveformShortStr(_waveform);
}
std::string LFO::SyncStr(Sync s) const {
	switch(s) {
	case Sync::Off : return SyncOff_Str; break;
	case Sync::On : return SyncOn_Str; break;
	case Sync::Key : return SyncKey_Str; break;
	default :
		std::cerr << "LFO::SyncStr : impossible case";
		return std::string();
	}
}
std::string LFO::SyncStr() const {
	return SyncStr(_sync);
}
void LFO::print(int m) const {
	ps(m);
	printf("Waveform = %s\n", LFOWaveformStr().c_str());
	ps(m);
	printf("Rate = %d\n", _rate);
	ps(m);
	printf("Delay time = %d\n", _delayTime);
	ps(m);
	printf("Sync = %s\n", SyncStr().c_str());
}
