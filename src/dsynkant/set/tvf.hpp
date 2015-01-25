/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tvf.hpp

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

#ifndef __DSYNKANT_TVF_HPP
#define __DSYNKANT_TVF_HPP

#include "../commondef/commondef.hpp"
#include "basekeybias.hpp"
#include "baseenvelope.hpp"
#include "basemodulation.hpp"
#include "address.hpp"

namespace dsynkant {

class BaseKeyBias;
class BaseEnvelope;
class BaseModulation;

#define DUMP_TVF_LENGTH 8 + DUMP_KEYBIAS_LENGTH + DUMP_ENVELOPE_LENGTH + DUMP_MODULATION_LENGTH

/***********************/
/* Time Variant Filter */
/***********************/

class TVF : public BaseKeyBias, public BaseEnvelope, public BaseModulation {
private:
	unsigned char _cutoffFrequency; //between 0 and 100
	unsigned char _resonance; //between 0 and 30
	FracKeyFollow _cutoffPointKeyFollow; //but without s1 and s2
	unsigned char _ENVDepth; //between 0 and 100
	unsigned char _velocityRange; //between 0 and 100
	unsigned char _depthKeyFollow; //between 0 and 4
	unsigned char _timeKeyFollow; //between 0 and 4
	char _aftertouchRange; //between -7 and +7
public:
	TVF();
	~TVF();

	//affect methods
	void setCutoffFrequency(unsigned char cf);
	void setResonance(unsigned char r);
	void setCutoffPointKeyFollow(FracKeyFollow cpkf);
	void setENVDepth(unsigned char ed);
	void setVelocityRange(unsigned char vr);
	void setDepthKeyFollow(unsigned char dkf);
	void setTimeKeyFollow(unsigned char tkf);
	void setAftertouchRange(char ar);
  
	//access methods
	unsigned char getCutoffFrequency() const;
	unsigned char getResonance() const;
	FracKeyFollow getCutoffPointKeyFollow() const;
	unsigned char getENVDepth() const;
	unsigned char getVelocityRange() const;
	unsigned char getDepthKeyFollow() const;
	unsigned char getTimeKeyFollow() const;
	char getAftertouchRange() const;

	//dump method
	void dump(Address& a, unsigned length, const unsigned char* data);

	//print methods
	void print(int m) const;
};

} // ~namespace dsynkant

#endif
