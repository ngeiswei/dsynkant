/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    basemodulation.cpp

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

#include "basemodulation.hpp"
#include "../commondef/commondef.hpp"

/**************************/
/* Constructor destructor */
/**************************/
BaseModulation::BaseModulation() {
    _positivePhase = true;
    _LFOSelect = 2;
    _LFODepth = 0;
}

BaseModulation::~BaseModulation() {
}

/******************/
/* Affect methods */
/******************/
void BaseModulation::setLFOPhase(bool p) {
    _positivePhase = p;
}
void BaseModulation::setLFOSelect(unsigned char ls) {
    _LFOSelect = ls;
}
void BaseModulation::setLFODepth(unsigned char ld) {
    _LFODepth = ld;
}

/******************/
/* Access methods */
/******************/
bool BaseModulation::getLFOPhase() {
    return _positivePhase;
}
unsigned char BaseModulation::getLFOSelect() {
    return _LFOSelect;
}
unsigned char BaseModulation::getLFODepth() {
    return _LFODepth;
}

/***************/
/* dump method */
/***************/
void BaseModulation::dump(Address& a, unsigned length, unsigned char* data) {
    Address cura;
    unsigned index = 0;
    if(length > index && a == cura) {
        _positivePhase = (0 == data[index]%2);
        _LFOSelect = 1 + data[index]/2;
        index++;
        ++a;
    }
    ++cura;
    if(length > index && a == cura) {
        _LFODepth = data[index];
        ++a;
    }
}

/****************/
/* print method */
/****************/
void BaseModulation::print(int m) {
    ps(m);
    printf("Modulation = (LFO phase : %s, LFO select : %d, LFO depth : %d)\n",
           (_positivePhase? "+":"-"), _LFOSelect, _LFODepth);
}
