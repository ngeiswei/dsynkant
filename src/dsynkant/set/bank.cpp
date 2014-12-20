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
Bank::Bank() {
  _bankName = NULL;
}
Bank::Bank(char* bn) {
  _bankName = bn;
}

Bank::~Bank() {
}

void Bank::addPatch(Patch* p) {
  _patches.push_back(p);
}
Patch* Bank::getPatch(unsigned index) {
  if(index < _patches.size()) return _patches[index];
  else return NULL;
}

//print method
void Bank::print(int m) {
  ps(m);
  printf("Bank = %s\n", _bankName);
  for(unsigned i = 0; i < _patches.size(); i++) _patches[i]->print(m+2);
}
