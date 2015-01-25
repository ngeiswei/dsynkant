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

#include "bank.hpp"
#include "../commondef/commondef.hpp"
#include <stdio.h>

//constructor destructor
Bank::Bank() {}
Bank::Bank(const std::string& bn) : _bankName(bn) {}

Bank::~Bank() {}

void Bank::addPatch(const Patch& p) {
	_patches.push_back(p);
}
const Patch& Bank::getPatch(unsigned index) const {
	return _patches[index];
}
Patch& Bank::getPatch(unsigned index) {
	return _patches[index];
}

//print method
void Bank::print(int m) const {
	ps(m);
	printf("Bank = %s\n", _bankName.c_str());
	for(const Patch& patch : _patches) patch.print(m+2);
}
