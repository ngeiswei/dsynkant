/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tva.hpp

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

#ifndef __DSYNKANT_TVA_HPP
#define __DSYNKANT_TVA_HPP

#include "baseenvelope.hpp"
#include "basemodulation.hpp"
#include "basekeybias.hpp"
#include "address.hpp"

namespace dsynkant {

#define DUMP_TVA_LENGTH DUMP_KEYBIAS_LENGTH + DUMP_ENVELOPE_LENGTH + DUMP_MODULATION_LENGTH + 5

class BaseEnvelope;
class BaseKeyBias;
class BaseModulation;

/**************************/
/* Time Variant Amplifier */
/**************************/
class TVA : public BaseKeyBias, public BaseEnvelope, public BaseModulation {
private:
	unsigned char _level; //between 0 and 100
	char _velocityRange; //between -50 and +50
	unsigned char _velocityFollow; //between 0 and 4, shorten the time1
	unsigned char _keyFollow; //between 0 and 4, shorten the whole envelope
	//Aftertouch
	char _aftertouchRange; //between -7 and +7

public:
	// Constructor destructor
	TVA();
	~TVA();

	// Affect methods
	void setLevel(unsigned char l);
	void setVelocityRange(char vr);
	void setVelocityFollow(unsigned char vf);
	void setKeyFollow(unsigned char kf);
	void setAftertouchRange(char ar);

	// Access methods
	unsigned char getLevel() const;
	char getVelocityRange() const;
	unsigned char getVelocityFollow() const;
	unsigned char getKeyFollow() const;
	char getAftertouchRange() const;

	// Dump method. Note that 'a' will be incremented accordingly.
	void dump(Address& a, unsigned length, const unsigned char* data);

	// Print method
	void print(int m) const; // Print the TVA on the std output tabulated of m
};

} // ~namespace dsynkant

#endif
