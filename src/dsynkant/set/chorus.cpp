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

#include <iostream>

#include "chorus.hpp"
#include "../commondef/commondef.hpp"

//Constructor destructor
Chorus::Chorus() {
    _type = ChorusType::Chorus1;
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
ChorusType Chorus::getType() const {
    return _type;
}
unsigned char Chorus::getRate() const {
    return _rate;
}
unsigned char Chorus::getDepth() const {
    return _depth;
}
unsigned char Chorus::getBalance() const {
    return _balance;
}

void Chorus::dump(Address& a, unsigned length, const unsigned char* data) {
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
std::string Chorus::ChorusTypeStr(ChorusType t) const {
    switch(t) {
    case ChorusType::Chorus1 : return Chorus1Str; break;
    case ChorusType::Chorus2 : return Chorus2Str; break;
    case ChorusType::Flanger1 : return Flanger1Str; break;
    case ChorusType::Flanger2 : return Flanger2Str; break;
    case ChorusType::FeedbackChorus : return FeedbackChorusStr; break;
    case ChorusType::Tremolo : return TremoloStr; break;
    case ChorusType::ChorusTremolo : return ChorusTremoloStr; break;
    case ChorusType::Dimension : return DimensionStr; break;
    default :
        std::cerr << "Chorus::ChorusTypeStr : impossible case";
        return std::string();
    }
}
std::string Chorus::ChorusTypeStr() const {
    return ChorusTypeStr(_type);
}
void Chorus::print(int m) const {
    ps(m);
    printf("Chorus = (type : %s, rate : %d, depth : %d, balance : %d)\n",
           ChorusTypeStr().c_str(), _rate, _depth, _balance);
}
