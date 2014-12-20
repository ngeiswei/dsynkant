/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    lfo.cpp

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

#include "lfo.hpp"
#include "../commondef/commondef.hpp"
#include <stdio.h>

//Constructor destructor
LFO::LFO(unsigned char rate, Sync sync) {
  _waveform = TRI;
  _rate = rate;
  _delayTime = 0;
  _sync = sync;
}

LFO::~LFO() {
}

//affect methods
void LFO::setWaveform(LFOWaveform wf) {
  _waveform = wf;
}
void LFO::setRate(unsigned char r) {
  _rate = r;
}
void LFO::setDelayTime(unsigned char dt) {
  _delayTime = dt;
}
void LFO::setSync(Sync s) {
  _sync = s;
}

//access methods
LFOWaveform LFO::getWaveform() {
  return _waveform;
}
unsigned char LFO::getRate() {
  return _rate;
}
unsigned char LFO::getDelayTime() {
  return _delayTime;
}
Sync LFO::getSync() {
  return _sync;
}

//dump method
void LFO::dump(Address& a, unsigned length, unsigned char* data) {
  Address cura;
  unsigned index = 0;
  if(length > index && a == cura) {
    _waveform = (LFOWaveform)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _rate = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _delayTime = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _sync = (Sync)data[index];
    ++a;
  }
}

//print method
char* LFO::LFOWaveformStr(LFOWaveform wf) {
  switch(wf) {
  case TRI : return TRI_Str; break;
  case SAW : return SAW_Str; break;
  case SQU : return SQU_Str; break;
  case RND : return RND_Str; break;
  default :
    printf("LFO::LFOWaveformStr error : impossible case\n");
    return NULL;
    break;
  }
}
char* LFO::LFOWaveformStr() {
  return LFOWaveformStr(_waveform);
}
char* LFO::LFOWaveformShortStr(LFOWaveform wf) {
  switch(wf) {
  case TRI : return TRI_Short_Str; break;
  case SAW : return SAW_Short_Str; break;
  case SQU : return SQU_Short_Str; break;
  case RND : return RND_Short_Str; break;
  default :
    printf("LFO::LFOWaveformStr error : impossible case\n");
    return NULL;
    break;
  }
}
char* LFO::LFOWaveformShortStr() {
  return LFOWaveformShortStr(_waveform);
}
char* LFO::SyncStr(Sync s) {
  switch(s) {
  case SyncOff : return SyncOff_Str; break;
  case SyncOn : return SyncOn_Str; break;
  case SyncKey : return SyncKey_Str; break;
  default :
    printf("LFO::SyncStr : impossible case\n");
    return NULL;
    break;
  }
}
char* LFO::SyncStr() {
  return SyncStr(_sync);
}
void LFO::print(int m) {
  ps(m);
  printf("Waveform = %s\n", LFOWaveformStr());
  ps(m);
  printf("Rate = %d\n", _rate);
  ps(m);
  printf("Delay time = %d\n", _delayTime);
  ps(m);
  printf("Sync = %s\n", SyncStr());
}
