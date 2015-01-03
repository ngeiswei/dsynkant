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

#include <string>

#include "address.hpp"

#define DUMP_CHORUS_LENGTH 4

const std::string Chorus1Str="Chorus 1";
const std::string Chorus2Str="Chorus 2";
const std::string Flanger1Str="Flanger 1";
const std::string Flanger2Str="Flanger 2";
const std::string FeedbackChorusStr="Feedback Chorus";
const std::string TremoloStr="Tremolo";
const std::string ChorusTremoloStr="Chorus Tremolo";
const std::string DimensionStr="Dimension";

enum class ChorusType {
    Chorus1,
    Chorus2,
    Flanger1,
    Flanger2,
    FeedbackChorus,
    Tremolo,
    ChorusTremolo,
    Dimension
};

class Chorus {
private:
    ChorusType _type;
    unsigned char _rate;
    unsigned char _depth;
    unsigned char _balance;
  
public:
    Chorus();
    ~Chorus();
  
    // Affect methods
    void setType(ChorusType t);
    void setRate(unsigned char r);
    void setDepth(unsigned char d);
    void setBalance(unsigned char b);

    // Access methods
    ChorusType getType() const;
    unsigned char getRate() const;
    unsigned char getDepth() const;
    unsigned char getBalance() const;

    // Dump method. Note that 'a' will be incremented accordingly.
    void dump(Address& a, unsigned length, const unsigned char* data);

    // Print and float methods
    std::string ChorusTypeStr(ChorusType t) const;
    std::string ChorusTypeStr() const;
    void print(int m) const;
};

#endif
