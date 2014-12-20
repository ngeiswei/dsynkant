/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    common.cpp

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

#include "common.hpp"
#include "../commondef/commondef.hpp"
#include <stdio.h>
#include <string.h>

//constructor destrtuctor
Common::Common(bool partial1On, bool partial2On) {
    setToneName("Init");
    _structure = SS;
    _tvp = new TVP();
    _lfo1 = new LFO();
    _lfo2 = new LFO();
    _lfo3 = new LFO();
    _eq = new EQ();
    _chorus = new Chorus();
    _partial1On = partial1On;
    _partial2On = partial2On;
    _partialBalance = 50;
}

Common::~Common() {
    delete(_tvp);
    delete(_lfo1);
    delete(_lfo2);
    delete(_lfo3);
    delete(_eq);
    delete(_chorus);
}

//affect methods  
void Common::setToneName(char* s) {
    strncpy(_toneName, s, TONENAME_LENGTH);
    _toneName[TONENAME_LENGTH] = '\0';
}
void Common::setPartial1On(bool on) {
    _partial1On = on;
}
void Common::setPartial2On(bool on) {
    _partial2On = on;
}
void Common::setPartialBalance(unsigned char pb) {
    _partialBalance = pb;
}

//access methods
char* Common::getToneName() {
    return _toneName;
}
unsigned char Common::getPartialBalance() {
    return _partialBalance;
}
bool Common::isPartial1On() {
    return _partial1On;
}
bool Common::isPartial2On() {
    return _partial2On;
}

//dump method
void Common::dump(Address& a, unsigned length, unsigned char* data) {
    Address lowBound;
    Address upBound(TONENAME_LENGTH);
    unsigned index = 0;
    if(a == lowBound) {
        while(index < length && index < TONENAME_LENGTH) {
            _toneName[index] = D50CharToASCII(data[index]);
            index++;
            ++a;
        }
        _toneName[index] = '\0';
    }
    lowBound += TONENAME_LENGTH;
    ++upBound; 
    if(length > index && a == lowBound) {
        _structure = (Structure) data[index];
        index++;
        ++a;
    }
    ++lowBound;
    upBound += DUMP_TVP_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        _tvp->dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_TVP_LENGTH;
    upBound += DUMP_LFO_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        _lfo1->dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_LFO_LENGTH;
    upBound += DUMP_LFO_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        _lfo2->dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_LFO_LENGTH;
    upBound += DUMP_LFO_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        _lfo3->dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_LFO_LENGTH;
    upBound += DUMP_EQ_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        _eq->dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_EQ_LENGTH;
    upBound += DUMP_CHORUS_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        _chorus->dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_CHORUS_LENGTH;
    if(length > index && a == lowBound) {
        _partial1On = (bool)(data[index] & 1);
        _partial2On = (bool)(data[index] & 2);    
        index++;
        ++a;
    }
    ++lowBound;
    if(length > index && a == lowBound) {
        _partialBalance = data[index];
        Address last(DUMP_COMMON_LENGTH);
        a = last;
    }
}

//print methods
char* Common::StructureStr(Structure s) {
    switch(s) {
    case SS : return SSStr; break;
    case SSR : return SSRStr; break;
    case PS : return PSStr; break;
    case PSR : return PSRStr; break;
    case SPR : return SPRStr; break;
    case PP : return PPStr; break;
    case PPR : return PPRStr; break;
    default :
        printf("Common::StructureStr : impossible case\n");
        return NULL;
        break;
    }
}
char* Common::StructureStr() {
    return StructureStr(_structure);
}
void Common::print(int m) {
    ps(m);
    printf("Tone name = %s\n", _toneName);
    ps(m);
    printf("Structure = %s\n", StructureStr());
    _tvp->print(m);
    _lfo1->print(m);
    _lfo2->print(m);
    _lfo3->print(m);
    _eq->print(m);
    _chorus->print(m);
    ps(m);
    printf("Partial mute = (P1 : %d, P2 : %d)\n",
           isPartial1On(), isPartial2On());
    ps(m);
    printf("Partial banlance = %d\n", _partialBalance);
}
