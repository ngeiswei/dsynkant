/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    lfo.hpp

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

#ifndef __LFO_HPP
#define __LFO_HPP

#include "address.hpp"

#define DUMP_LFO_LENGTH 4

#define TRI_Short_Str "TRI"
#define SAW_Short_Str "SAW"
#define SQU_Short_Str "SQU"
#define RND_Short_Str "RND"

#define TRI_Str "Triangle"
#define SAW_Str "Sawtooth"
#define SQU_Str "Square"
#define RND_Str "Random"

typedef enum {
    TRI,
    SAW,
    SQU,
    RND
} LFOWaveform;

#define SyncOff_Str "off"
#define SyncOn_Str "on"
#define SyncKey_Str "key"

typedef enum {
    SyncOff,
    SyncOn,
    SyncKey
} Sync;

class LFO {
private:
    LFOWaveform _waveform;
    unsigned char _rate; //betweem 0 and 100
    unsigned char _delayTime; //between 0 and 100
    Sync _sync;
  
public:
    LFO(unsigned char _rate = 50, Sync sync = SyncOff);
    ~LFO();
  
    //affect methods
    void setWaveform(LFOWaveform wf);
    void setRate(unsigned char r);
    void setDelayTime(unsigned char dt);
    void setSync(Sync s);

    //access methods
    LFOWaveform getWaveform();
    unsigned char getRate();
    unsigned char getDelayTime();
    Sync getSync();

    //dump method
    void dump(Address& a, unsigned length, unsigned char* data);

    //print method
    char* LFOWaveformStr(LFOWaveform wf);
    char* LFOWaveformStr();
    char* LFOWaveformShortStr(LFOWaveform wf);
    char* LFOWaveformShortStr();
    char* SyncStr(Sync s);
    char* SyncStr();
    void print(int m);
};

#endif
