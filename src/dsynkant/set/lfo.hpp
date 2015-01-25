/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    lfo.hpp

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

#ifndef __DSYNKANT_LFO_HPP
#define __DSYNKANT_LFO_HPP

#include <string>

#include "address.hpp"

namespace dsynkant {

#define DUMP_LFO_LENGTH 4

const std::string TRI_Short_Str="TRI";
const std::string SAW_Short_Str="SAW";
const std::string SQU_Short_Str="SQU";
const std::string RND_Short_Str="RND";

const std::string TRI_Str="Triangle";
const std::string SAW_Str="Sawtooth";
const std::string SQU_Str="Square";
const std::string RND_Str="Random";

enum class LFOWaveform {
	TRI,
		SAW,
		SQU,
		RND
		};

const std::string SyncOff_Str="off";
const std::string SyncOn_Str="on";
const std::string SyncKey_Str="key";

enum class Sync {
	Off,
		On,
		Key
		};

class LFO {
private:
	LFOWaveform _waveform;
	unsigned char _rate; // Betweem 0 and 100
	unsigned char _delayTime; // Between 0 and 100
	Sync _sync;
  
public:
	LFO(unsigned char _rate = 50, Sync sync = Sync::Off);
	~LFO();
  
	// Affect methods
	void setWaveform(LFOWaveform wf);
	void setRate(unsigned char r);
	void setDelayTime(unsigned char dt);
	void setSync(Sync s);

	// Access methods
	LFOWaveform getWaveform() const;
	unsigned char getRate() const;
	unsigned char getDelayTime() const;
	Sync getSync() const;

	// Dump method. Note that 'a' will be incremented accordingly.
	void dump(Address& a, unsigned length, const unsigned char* data);

	// Print method
	std::string LFOWaveformStr(LFOWaveform wf) const;
	std::string LFOWaveformStr() const;
	std::string LFOWaveformShortStr(LFOWaveform wf) const;
	std::string LFOWaveformShortStr() const;
	std::string SyncStr(Sync s) const;
	std::string SyncStr() const;
	void print(int m) const;
};

} // ~namespace dsynkant

#endif
