/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tva.cpp

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

#include "tva.hpp"
#include "../commondef/commondef.hpp"

/**************************/
/* Constructor destructor */
/**************************/
TVA::TVA() : BaseKeyBias(KBTVA) {
    _level = 100;
    _velocityRange = 0;
    _velocityFollow = 0;
    _keyFollow = 0;
    _aftertouchRange = 0;
}

TVA::~TVA() {
}

/******************/
/* Affect methods */
/******************/
void TVA::setLevel(unsigned char l) {
    _level = l;
}
void TVA::setVelocityRange(char vr) {
    _velocityRange = vr;
}
void TVA::setVelocityFollow(unsigned char vf) {
    _velocityFollow = vf;
}
void TVA::setKeyFollow(unsigned char kf) {
    _keyFollow = kf;
}
void TVA::setAftertouchRange(char ar) {
    _aftertouchRange = ar;
}

/******************/
/* Access methods */
/******************/
unsigned char TVA::getLevel() {
    return _level;
}
char TVA::getVelocityRange() {
    return _velocityRange;
}
unsigned char TVA::getVelocityFollow() {
    return _velocityFollow;
}
unsigned char TVA::getKeyFollow() {
    return _keyFollow;
}
char TVA::getAftertouchRange() {
    return _aftertouchRange;
}

/****************/
/* dump method */
/****************/
void TVA::dump(Address& a, unsigned length, unsigned char* data) {
    Address lowBound;
    Address upBound(1);
    unsigned index = 0;
    if(length > index && a == lowBound) {
        _level = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    ++upBound;
    if(length > index && a == lowBound) {
        _velocityRange = (char)data[index] - 50;
        index++;
        ++a;
    }
    ++lowBound;
    upBound += DUMP_KEYBIAS_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound; //local address
        Address prela = la; //to keep before the dump
        BaseKeyBias::dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_KEYBIAS_LENGTH;
    upBound += DUMP_ENVELOPE_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound; //local address
        Address prela = la; //to keep before the dump
        BaseEnvelope::dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_ENVELOPE_LENGTH;
    ++upBound;
    if(length > index && a == lowBound) {
        _velocityFollow = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    ++upBound;  
    if(length > index && a == lowBound) {
        _keyFollow = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    upBound += DUMP_MODULATION_LENGTH;
    if(length > index && a >= lowBound) {
        Address la = a - lowBound;
        Address prela = la;
        BaseModulation::dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_MODULATION_LENGTH;
    ++upBound;
    if(length > index) {
        _aftertouchRange = (char)data[index] - 7;
        ++a;
    }
}

/****************/
/* print method */
/****************/
void TVA::print(int m) {
    ps(m);
    printf("Level = %d\n", _level);
    ps(m);
    printf("Velocity range = %d\n", _velocityRange);
    BaseKeyBias::print(m);
    BaseEnvelope::print(m);
    ps(m);
    printf("Velocity follow = %d\n", _velocityFollow);
    ps(m);
    printf("Key follow = %d\n", _keyFollow);
    BaseModulation::print(m);
    ps(m);
    printf("Aftertouch range = %d\n", _aftertouchRange);
}
