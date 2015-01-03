/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    basekeybias.cpp

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

#include "basekeybias.hpp"
#include "../commondef/commondef.hpp"
#include <string.h>

/**************************/
/* Constructor destructor */
/**************************/
BaseKeyBias::BaseKeyBias(KeyBiasType t) {
    _type = t;
    _biasRangeUp = true;
    _biasRangeKey = 27; //corresponds to C4;
    _biasLevel = 0;
}

BaseKeyBias::~BaseKeyBias() {
}

/******************/
/* Affect methods */
/******************/
void BaseKeyBias::setBiasRangeUp(bool bru) {
    _biasRangeUp = bru;
}
void BaseKeyBias::setBiasRangeKey(unsigned char brk) {
    _biasRangeKey = brk;
}
void BaseKeyBias::setBiasLevel(char bl) {
    _biasLevel = bl;
}


/******************/
/* Access methods */
/******************/
bool BaseKeyBias::getBiasRangeUp() const {
    return _biasRangeUp;
}
unsigned char BaseKeyBias::getBiasRangeKey() const {
    return _biasRangeKey;
}
char BaseKeyBias::getBiasLevel() const {
    return _biasLevel;
}

void BaseKeyBias::dump(Address& a, unsigned length, const unsigned char* data) {
    Address cura;
    unsigned index = 0;
    if(length > index && a == cura) {
        _biasRangeUp = data[index] > 63;
        _biasRangeKey = data[index] % 64;
        index++;
        ++a;
    }
    ++cura;
    if(length > index && a == cura) {
        _biasLevel = (char)data[index] - (_type == KBTVF?7:12);
        ++a;
    }  
}

/****************/
/* print method */
/****************/
char* BaseKeyBias::pitchStr(int p) const {
    p += 9; //to be A1
    int octave = p/12 + 1;
    char sOct[INT_STR_LENGTH];
    sprintf(sOct, "%d", octave);
    int note = p%12;
    char sNote[INT_STR_LENGTH];
    switch(note) {
    case 0: strcpy(sNote, "C"); break;
    case 1: strcpy(sNote, "C#"); break;
    case 2: strcpy(sNote, "D"); break;
    case 3: strcpy(sNote, "D#"); break;
    case 4: strcpy(sNote, "E"); break;
    case 5: strcpy(sNote, "F"); break;
    case 6: strcpy(sNote, "F#"); break;
    case 7: strcpy(sNote, "G"); break;
    case 8: strcpy(sNote, "G#"); break;
    case 9: strcpy(sNote, "A"); break;
    case 10: strcpy(sNote, "A#"); break;
    case 11: strcpy(sNote, "F"); break;
    default:
        printf("pitchStr Error : impossible case\n");
        break;
    }
    return strcat(sNote, sOct);
}

void BaseKeyBias::print(int m) const {
    ps(m);
    printf("Bias = ");
    if(_biasRangeUp) printf(">");
    else printf("<");
    printf("%s\n", pitchStr(_biasRangeKey));
    ps(m);
    printf("Bias level = %d\n", _biasLevel);  
}
