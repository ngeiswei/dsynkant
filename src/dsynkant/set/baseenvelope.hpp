/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    baseenvelope.hpp

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

#ifndef __BASEENVELOPE_HPP
#define __BASEENVELOPE_HPP

#include "address.hpp"

#define DUMP_ENVELOPE_LENGTH 10

/*****************/
/* Base Envelope */
/*****************/
class BaseEnvelope {
private:
    unsigned char _time1; //between 0 and 100,
    unsigned char _level1; //between 0 and 100,
    unsigned char _time2; //between 0 and 100,
    unsigned char _level2; //between 0 and 100,
    unsigned char _time3; //between 0 and 100
    unsigned char _level3; //between 0 and 100
    unsigned char _time4; //between 0 and 100
    unsigned char _sustainLevel; //between 0 and 100
    unsigned char _time5; //between 0 and 100
    unsigned char _endLevel; //between 0 and 100

public:
    //constructor destructor
    BaseEnvelope();
    ~BaseEnvelope();

    //affect methods
    void setTime1(unsigned char t1);
    void setLevel1(unsigned char l1);
    void setTime2(unsigned char t2);
    void setLevel2(unsigned char l2);
    void setTime3(unsigned char t3);
    void setLevel3(unsigned char l3);
    void setTime4(unsigned char t4);
    void setSustainLevel(unsigned char sl);
    void setTime5(unsigned char t5);
    void setEndLevel(unsigned char el);

    //access methods
    unsigned char getTime1();
    unsigned char getLevel1();
    unsigned char getTime2();
    unsigned char getLevel2();
    unsigned char getTime3();
    unsigned char getLevel3();
    unsigned char getTime4();
    unsigned char getSustainLevel();
    unsigned char getTime5();
    unsigned char getEndLevel();

    //bump method
    void dump(Address& a, unsigned length, unsigned char* data);

    //print method
    void print(int m); //print the envelope on the std output tabulated of m
};

#endif
