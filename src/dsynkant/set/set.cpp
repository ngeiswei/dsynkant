/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    bank.cpp

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

#include "set.hpp"
#include "../commondef/commondef.hpp"
#include <stdio.h>

//constructor destructor
Set::Set() {}
Set::Set(const std::string& bn) : _setName(bn) {}
Set::~Set() {}

void Set::addBank(const Bank& b) {
	_banks.push_back(b);
}
const Bank& Set::getBank(unsigned index) const {
	return _banks[index];
}
Bank& Set::getBank(unsigned index) {
	return _banks[index];
}

//dump method
void Set::dump(unsigned length, const unsigned char* data) {
	//TODO
}

//print method
void Set::print(int m) const {
	ps(m);
	printf("Set = %s\n", _setName.c_str());
	for(const Bank& bank : _banks) bank.print(m+2);
}
