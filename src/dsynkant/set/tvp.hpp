/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    tvp.hpp

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

#ifndef __TVP_HPP
#define __TVP_HPP

#include "address.hpp"

#define DUMP_TVP_LENGTH 14

/**********************/
/* Time Variant Pitch */
/**********************/
class TVP {
private:
    unsigned char _velocityRange; //between 0 and 2,
    //case 0: +-50 <=> +-1octave
    //case 1: +-50 <=> +-1.5octave
    //case 2: +-50 <=> +-2octave
    unsigned char _keyFollow; //between 0 and 4, shorten the whole envelope
    //envelope
    char _level0; //between -50 and +50
    unsigned char _time1; //between 0 and 50
    char _level1; //between -50 and +50
    unsigned char _time2; //between 0 and 50
    char _level2; //between -50 and +50
    unsigned char _time3; //between 0 and 50
    char _sustainLevel; //between -50 and +50
    unsigned char _time4; //between 0 and 50
    char _endLevel; //between -50 and +50
    //modulation
    unsigned char _LFODepth; //between 0 and 100,
    //depth of LFO-1 that controls the WG pitch
    unsigned char _pitchLeverModulation; //between 0 and 100
    unsigned char _pitchAftertouchModulation; //between 0 and 100

public:
    // Constructor destructor
    TVP();
    ~TVP();

    // Affect methods
    void setVelocityRange(unsigned char vr);
    void setKeyFollow(unsigned char kf);
    void setLevel0(char l0);
    void setTime1(unsigned char t1);
    void setLevel1(char l1);
    void setTime2(unsigned char t2);
    void setLevel2(char l2);
    void setTime3(unsigned char t3);
    void setSustainLevel(char sl);
    void setTime4(unsigned char t4);
    void setEndLevel(char el);
    void setLFODepth(unsigned char ld);
    void setPitchLeverModulation(unsigned char plm);
    void setPitchAftertouchModulation(unsigned char pam);

    // Dump method. Note that 'a' will be incremented accordingly.
    void dump(Address& a, unsigned length, const unsigned char* data);

    // Access methods
    unsigned char getVelocityRange() const;
    unsigned char getKeyFollow() const;
    char getLevel0() const;
    unsigned char getTime1() const;
    char getLevel1() const;
    unsigned char getTime2() const;
    char getLevel2() const;
    unsigned char getTime3() const;
    char getSustainLevel() const;
    unsigned char getTime4() const;
    char getEndLevel() const;
    unsigned char getLFODepth() const;
    unsigned char getPitchLeverModulation() const;
    unsigned char getPitchAftertouchModulation() const;

    // Print the TVP on the std output tabulated of m
    void print(int m) const;
};

#endif
