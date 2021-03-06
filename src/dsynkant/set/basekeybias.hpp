/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    basekeybias.hpp

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

#ifndef __DSYNKANT_BASEKEYBIAS_HPP
#define __DSYNKANT_BASEKEYBIAS_HPP

#include "address.hpp"

namespace dsynkant {

#define DUMP_KEYBIAS_LENGTH 2

#define INT_STR_LENGTH 256

typedef enum {
	KBTVF,
	KBTVA
} KeyBiasType;

/*****************/
/* Base Key Bias */
/*****************/
class BaseKeyBias {
private:
	bool _biasRangeUp; //if true then bias range is greater than the range
	unsigned char _biasRangeKey; //key number of the bias range
	char _biasLevel; //between -12 and 0 (if TVA) or -7 and +7 (TVF)

	KeyBiasType _type; //this is just to know if it used by TVF or TVA

public:
	// Constructor destructor
	BaseKeyBias(KeyBiasType t);
	~BaseKeyBias();

	// Affect methods
	void setBiasRangeUp(bool bru);
	void setBiasRangeKey(unsigned char brk);
	void setBiasLevel(char bl);

	// Access methods
	bool getBiasRangeUp() const;
	unsigned char getBiasRangeKey() const;
	char getBiasLevel() const;

	// Dump method. Note that 'a' will be incremented accordingly.
	void dump(Address& a, unsigned length, const unsigned char* data);

	// Print method
	char* pitchStr(int p) const;
	void print(int m) const; // Print the key bias on the std output tabulated of m
};

} // ~namespace dsynkant

#endif
