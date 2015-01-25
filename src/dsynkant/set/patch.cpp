/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    patch.cpp

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

#include "patch.hpp"
#include "../commondef/commondef.hpp"

using namespace dsynkant;

//constructor destructor
Patch::Patch() 
	: _lowerCommon(true) /* only partial 1 */ {}

Patch::~Patch() {}

//dump method
void Patch::dump(Address& a, unsigned length, const unsigned char* data) {
	Address lowBound(0, 0);
	Address upBound(0, DUMP_PARTIAL_LENGTH);
	unsigned index = 0;
	//Upper partial 1
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound; //local address
		Address prela = la; //to keep before the dump
		_upperPartial1.dump(la, length, data);
		Address diffa = la - prela; //distance made by dump
		index += diffa.toInt();
		a += diffa;
	}
	lowBound += DUMP_PARTIAL_LENGTH;
	upBound += DUMP_PARTIAL_LENGTH;
	//Upper partial 2
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound;
		Address prela = la;
		_upperPartial2.dump(la, length - index, &data[index]);
		Address diffa = la - prela;
		index += diffa.toInt();
		a += diffa;
	}
	lowBound += DUMP_PARTIAL_LENGTH;
	upBound += DUMP_COMMON_LENGTH;
	//Upper common 
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound;
		Address prela = la;
		_upperCommon.dump(la, length - index, &data[index]);
		Address diffa = la - prela;
		index += diffa.toInt();
		a += diffa;
	}
	lowBound += DUMP_COMMON_LENGTH;
	upBound += DUMP_PARTIAL_LENGTH;
	//Lower partial 1
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound;
		Address prela = la;
		_lowerPartial1.dump(la, length - index, &data[index]);
		Address diffa = la - prela;
		index += diffa.toInt();  
		a += diffa;
	}
	lowBound += DUMP_PARTIAL_LENGTH;
	upBound += DUMP_PARTIAL_LENGTH;
	//Lower partial 2
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound;
		Address prela = la;
		_lowerPartial2.dump(la, length - index, &data[index]);
		Address diffa = la - prela;
		index += diffa.toInt();
		a += diffa;
	}
	lowBound += DUMP_PARTIAL_LENGTH;
	upBound += DUMP_COMMON_LENGTH;
	//Lower common
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound;
		Address prela = la;
		_lowerCommon.dump(la, length - index, &data[index]);
		Address diffa = la - prela;
		index += diffa.toInt();
		a += diffa;
	}
	lowBound += DUMP_COMMON_LENGTH;
	upBound += DUMP_PATCHPARAMETER_LENGTH;
	//Patch parameter
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound;
		Address prela = la;
		_patchParameter.dump(la, length - index, &data[index]);
		Address diffa = la - prela;
		a += diffa;
	}
}

//print method
void Patch::print(int m) const {
	ps(m);
	printf("Upper Partial 1\n");
	_upperPartial1.print(m+2);
	ps(m);
	printf("Upper Partial 2\n");
	_upperPartial2.print(m+2);
	ps(m);
	printf("Upper Common\n");
	_upperCommon.print(m+2);
	ps(m);
	printf("Lower Partial 1\n");
	_lowerPartial1.print(m+2);
	ps(m);
	printf("Lower Partial 2\n");
	_lowerPartial2.print(m+2);
	ps(m);
	printf("Lower Common\n");
	_lowerCommon.print(m+2);
	ps(m);
	printf("Patch Parameter\n");
	_patchParameter.print(m+2);
}
