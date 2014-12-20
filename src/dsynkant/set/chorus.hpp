/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    chorus.hpp

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

#ifndef __CHORUS_HPP
#define __CHORUS_HPP

#include "address.hpp"

#define DUMP_CHORUS_LENGTH 4

#define Chorus1Str "Chorus 1"
#define Chorus2Str "Chorus 2"
#define Flanger1Str "Flanger 1"
#define Flanger2Str "Flanger 2"
#define FeedbackChorusStr "Feedback Chorus"
#define TremoloStr "Tremolo"
#define ChorusTremoloStr "Chorus Tremolo"
#define DimensionStr "Dimension"

typedef enum {
  Chorus1,
  Chorus2,
  Flanger1,
  Flanger2,
  FeedbackChorus,
  Tremolo,
  ChorusTremolo,
  Dimension
} ChorusType;

class Chorus {
private:
  ChorusType _type;
  unsigned char _rate;
  unsigned char _depth;
  unsigned char _balance;
  
public:
  Chorus();
  ~Chorus();
  
  //affect methods
  void setType(ChorusType t);
  void setRate(unsigned char r);
  void setDepth(unsigned char d);
  void setBalance(unsigned char b);

  //access methods
  ChorusType getType();
  unsigned char getRate();
  unsigned char getDepth();
  unsigned char getBalance();  

  //dump method
  void dump(Address& a, unsigned length, unsigned char* data);

  //print and float methods
  char* ChorusTypeStr(ChorusType t);
  char* ChorusTypeStr();
  void print(int m);
};

#endif
