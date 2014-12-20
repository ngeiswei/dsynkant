/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tvp.cpp

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

#include "tvp.hpp"
#include "../commondef/commondef.hpp"

/**************************/
/* Constructor destructor */
/**************************/
TVP::TVP() {
    _velocityRange = 0;
    _keyFollow = 0;
    _level0 = 0;
    _time1 = 0;
    _level1 = 0;
    _time2 = 50;
    _level2 = 0;
    _time3 = 50;
    _sustainLevel = 0;
    _time4 = 50;
    _endLevel = 0;
    _LFODepth = 0;
    _pitchLeverModulation = 20;
    _pitchAftertouchModulation = 0;
}

TVP::~TVP() {
}

/******************/
/* Affect methods */
/******************/
void TVP::setVelocityRange(unsigned char vr) {
    _velocityRange = vr;
}
void TVP::setKeyFollow(unsigned char kf) {
    _keyFollow = kf;
}
void TVP::setLevel0(char l0) {
    _level0 = l0;
}
void TVP::setTime1(unsigned char t1) {
    _time1 = t1;
}
void TVP::setLevel1(char l1) {
    _level1 = l1;
}
void TVP::setTime2(unsigned char t2) {
    _time2 = t2;
}
void TVP::setLevel2(char l2) {
    _level2 = l2;
}
void TVP::setTime3(unsigned char t3) {
    _time3 = t3;
}
void TVP::setSustainLevel(char sl) {
    _sustainLevel = sl;
}
void TVP::setTime4(unsigned char t4) {
    _time4 = t4;
}
void TVP::setEndLevel(char el) {
    _endLevel = el;
}
void TVP::setLFODepth(unsigned char ld) {
    _LFODepth = ld;
}
void TVP::setPitchLeverModulation(unsigned char plm) {
    _pitchLeverModulation = plm;
} 
void TVP::setPitchAftertouchModulation(unsigned char pam) {
    _pitchAftertouchModulation = pam;
}

/******************/
/* Access methods */
/******************/
unsigned char TVP::getVelocityRange() {
    return _velocityRange;
}
unsigned char TVP::getKeyFollow() {
    return _keyFollow;
}
char TVP::getLevel0() {
    return _level0;
}
unsigned char TVP::getTime1() {
    return _time1;
}
char TVP::getLevel1() {
    return _level1;
}
unsigned char TVP::getTime2() {
    return _time2;
}
char TVP::getLevel2() {
    return _level2;
}
unsigned char TVP::getTime3() {
    return _time3;
}
char TVP::getSustainLevel() {
    return _sustainLevel;
}
unsigned char TVP::getTime4() {
    return _time4;
}
char TVP::getEndLevel() {
    return _endLevel;
}
unsigned char TVP::getLFODepth() {
    return _LFODepth;
}
unsigned char TVP::getPitchLeverModulation() {
    return _pitchLeverModulation;
} 
unsigned char TVP::getPitchAftertouchModulation() {
    return _pitchAftertouchModulation;
}

/***************/
/* dump method */
/***************/
void TVP::dump(Address& a, unsigned length, unsigned char* data) {
    Address cura;
    unsigned index = 0;
    if(length > index) {
        _velocityRange = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _keyFollow = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _time1 = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _time2 = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _time3 = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _time4 = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _level0 = (char)data[index] - 50;
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _level1 = (char)data[index] - 50;
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _level2 = (char)data[index] - 50;
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _sustainLevel = (char)data[index] - 50;
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _endLevel = (char)data[index] - 50;
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _LFODepth = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _pitchLeverModulation = data[index];
        index++;
        ++a;
    }
    ++cura;
    if(length > index) {
        _pitchAftertouchModulation = data[index];
        ++a;
    }
}

/****************/
/* print method */
/****************/
void TVP::print(int m) {
    ps(m);
    printf("Velocity range = %d\n", _velocityRange);
    ps(m);
    printf("Key follow = %d\n", _keyFollow);
    ps(m);
    printf("Env = (l0:%d,t1:%d,l1:%d,t2:%d,l2:%d,t3:%d,sl:%d,t4:%d,el:%d)\n",
           _level0, _time1, _level1, _time2, _level2, _time3, _sustainLevel,
           _time4, _endLevel);
    ps(m);
    printf("Modulation = (LFODepth : %d, PLM : %d, PAM : %d)\n",
           _LFODepth, _pitchLeverModulation, _pitchAftertouchModulation);
}
