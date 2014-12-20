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
Set::Set() {
  _setName = NULL;
}
Set::Set(char* bn) {
  _setName = bn;
}

Set::~Set() {
}

void Set::addBank(Bank* b) {
  _banks.push_back(b);
}
Bank* Set::getBank(unsigned index) {
  if(index < _banks.size()) return _banks[index];
  else return NULL;
}

//dump method
void Set::dump(unsigned length, unsigned char* data) {
  //TODO
}

//print method
void Set::print(int m) {
  ps(m);
  printf("Set = %s\n", _setName);
  for(unsigned i = 0; i < _banks.size(); i++) _banks[i]->print(m+2);
}
