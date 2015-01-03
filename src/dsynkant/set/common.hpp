/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    common.hpp

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

#ifndef __COMMON_HPP
#define __COMMON_HPP

#include <string>

#include "tvp.hpp"
#include "lfo.hpp"
#include "eq.hpp"
#include "chorus.hpp"
#include "address.hpp"

class TVP;
class LFO;
class EQ;
class Chorus;

#define DUMP_COMMON_LENGTH 0x40

#define TONENAME_LENGTH 10

#define SSStr "Mix(S,S)"
#define SSRStr "Mix(S,Ring(S,S))"
#define PSStr "Mix(P,S)"
#define PSRStr "Mix(P,Ring(P,S))"
#define SPRStr "Mix(S,Ring(S,P))"
#define PPStr "Mix(P,P)"
#define PPRStr "Mix(P,Ring(P,P))"

enum class Structure {
    SS, // Mix of synthe partial 1 and synthe partial 2
    SSR, // Mix of synthe partial 1 and ring mod of synthe partial 1 & 2
    PS, // Mix of PCM partial 1 and synthe partial 2
    PSR, // Mix of PCM partial 1 and ring mod of synthe partial 1 & 2
    SPR, // Mix of synthe partial 1 and ring mod of PCM partial 1 & 2
    PP, // Mix of PCM partial 1 and PCM partial 2
    PPR // Mix of PCM partial 1 and rinf mod of PCM partial 1 & 2
};

class Common {
private:
    std::string _toneName;
    Structure _structure;
    TVP _tvp;
    LFO _lfo1;
    LFO _lfo2;
    LFO _lfo3;
    EQ _eq;
    Chorus _chorus;
    bool _partial1On;
    bool _partial2On;
    unsigned char _partialBalance;

public:
    Common(bool partial1On = false, bool partial2On = false);
    ~Common();

    // Affect methods
    void setToneName(const std::string& s);
    void setPartial1On(bool on);
    void setPartial2On(bool on);
    void setPartialBalance(unsigned char pb);

    // Access methods
    const char* getToneName() const;
    bool isPartial1On() const;
    bool isPartial2On() const;
    unsigned char getPartialBalance() const;

    // Dump method. Note that 'a' will be incremented accordingly.
    void dump(Address& a, unsigned length, const unsigned char* data);

    // Print methods
    std::string StructureStr(Structure s) const;
    std::string StructureStr() const;
    void print(int m) const;
};

#endif
