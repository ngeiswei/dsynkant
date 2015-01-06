
/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tvf.cpp

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

#include "tvf.hpp"

// constructor destructor
TVF::TVF() : BaseKeyBias(KBTVF) {
    _cutoffFrequency = 50;
    _resonance = 0;
    _cutoffPointKeyFollow = FracKeyFollow::plus1div2;
    _ENVDepth = 0;
    _velocityRange = 0;
    _depthKeyFollow = 0;
    _timeKeyFollow = 0;
    _aftertouchRange = 0;
}
TVF::~TVF() {
}

//affect methods
void TVF::setCutoffFrequency(unsigned char cf) {
    _cutoffFrequency = cf;
}
void TVF::setResonance(unsigned char r) {
    _resonance = r;
}
void TVF::setCutoffPointKeyFollow(FracKeyFollow cpkf) {
    _cutoffPointKeyFollow = cpkf;
}
void TVF::setENVDepth(unsigned char ed) {
    _ENVDepth = ed;
}
void TVF::setVelocityRange(unsigned char vr) {
    _velocityRange = vr;
}
void TVF::setDepthKeyFollow(unsigned char dkf) {
    _depthKeyFollow = dkf;
}
void TVF::setTimeKeyFollow(unsigned char tkf) {
    _timeKeyFollow = tkf;
}
void TVF::setAftertouchRange(char ar) {
    _aftertouchRange = ar;
}

//access methods
unsigned char TVF::getCutoffFrequency() const {
    return _cutoffFrequency;
}
unsigned char TVF::getResonance() const {
    return _resonance;
}
FracKeyFollow TVF::getCutoffPointKeyFollow() const {
    return _cutoffPointKeyFollow;
}
unsigned char TVF::getENVDepth() const {
    return _ENVDepth;
}
unsigned char TVF::getVelocityRange() const {
    return _velocityRange;
}
unsigned char TVF::getDepthKeyFollow() const {
    return _depthKeyFollow;
}
unsigned char TVF::getTimeKeyFollow() const {
    return _timeKeyFollow;
}
char TVF::getAftertouchRange() const {
    return _aftertouchRange;
}

//dump method
void TVF::dump(Address& a, unsigned length, const unsigned char* data) {
    Address lowBound;
    Address upBound(1);
    unsigned index = 0;
    if(length > index && a == lowBound) {
        _cutoffFrequency = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    ++upBound;
    if(length > index && a == lowBound) {
        _resonance = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    ++upBound;
    if(length > index && a == lowBound) {
        _cutoffPointKeyFollow = (FracKeyFollow)data[index];
        index++;
        ++a;
    }
    ++lowBound;
    upBound += DUMP_KEYBIAS_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        BaseKeyBias::dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_KEYBIAS_LENGTH;
    ++upBound;
    if(length > index && a == lowBound) {
        _ENVDepth = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    ++upBound;
    if(length > index && a == lowBound) {
        _velocityRange = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    ++upBound;
    if(length > index && a == lowBound) {
        _depthKeyFollow = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    ++upBound;
    if(length > index && a == lowBound) {
        _timeKeyFollow = data[index];
        index++;
        ++a;
    }
    ++lowBound;
    upBound += DUMP_ENVELOPE_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        BaseEnvelope::dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_ENVELOPE_LENGTH;
    upBound += DUMP_MODULATION_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound;
        Address prela = la;
        BaseModulation::dump(la, length - index, &data[index]);
        Address diffa = la - prela;
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_MODULATION_LENGTH;
    if(length > index && a == lowBound) {
        _aftertouchRange = (char)data[index] - 7;
        ++a;
    }
}

//print methods
void TVF::print(int m) const {
    ps(m);
    printf("Cutoff frequency = %d\n", _cutoffFrequency);
    ps(m);
    printf("Resonance = %d\n", _resonance);
    ps(m);
    printf("Cutoff point key follow = %s\n",
           FracKeyFollowStr(_cutoffPointKeyFollow).c_str());
    BaseKeyBias::print(m);
    ps(m);
    printf("Envelope depth = %d\n", _ENVDepth);
    ps(m);
    printf("Velocity range = %d\n", _velocityRange);
    ps(m);
    printf("Depth key follow = %d\n", _depthKeyFollow);
    ps(m);
    printf("Time key follow = %d\n", _timeKeyFollow);
    BaseEnvelope::print(m);
    BaseModulation::print(m);
    ps(m);
    printf("Aftertouch range = %d\n", _aftertouchRange);
}
