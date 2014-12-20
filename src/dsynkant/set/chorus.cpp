/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    chorus.cpp

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

#include "chorus.hpp"
#include "../commondef/commondef.hpp"

//Constructor destructor
Chorus::Chorus() {
  _type = Chorus1;
  _rate = 50;
  _depth = 50;
  _balance = 0;
}

Chorus::~Chorus() {
}

//affect methods
void Chorus::setType(ChorusType t) {
  _type = t;
}
void Chorus::setRate(unsigned char r) {
  _rate = r;
}
void Chorus::setDepth(unsigned char d) {
  _depth = d;
}
void Chorus::setBalance(unsigned char b) {
  _balance = b;
}

//access methods
ChorusType Chorus::getType() {
  return _type;
}
unsigned char Chorus::getRate() {
  return _rate;
}
unsigned char Chorus::getDepth() {
  return _depth;
}
unsigned char Chorus::getBalance() {
  return _balance;
}

//dump method
void Chorus::dump(Address& a, unsigned length, unsigned char* data) {
  Address cura;
  unsigned index = 0;
  if(length > index & a == cura) {
    _type = (ChorusType) data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index & a == cura) {
    _rate = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index & a == cura) {
    _depth = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index & a == cura) {
    _balance = data[index];
    ++a;
  }
}

//print methods
char* Chorus::ChorusTypeStr(ChorusType t) {
  switch(t) {
  case Chorus1 : return Chorus1Str; break;
  case Chorus2 : return Chorus2Str; break;
  case Flanger1 : return Flanger1Str; break;
  case Flanger2 : return Flanger2Str; break;
  case FeedbackChorus : return FeedbackChorusStr; break;
  case Tremolo : return TremoloStr; break;
  case ChorusTremolo : return ChorusTremoloStr; break;
  case Dimension : return DimensionStr; break;
  default :
    printf("Chorus::ChorusTypeStr : impossible case\n");
    return NULL;
    break;
  }
}
char* Chorus::ChorusTypeStr() {
  return ChorusTypeStr(_type);
}
void Chorus::print(int m) {
  ps(m);
  printf("Chorus = (type : %s, rate : %d, depth : %d, balance : %d)\n",
	 ChorusTypeStr(), _rate, _depth, _balance);
}
