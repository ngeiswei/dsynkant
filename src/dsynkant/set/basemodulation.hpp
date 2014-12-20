/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    basemodulation.hpp

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

#ifndef __BASEMODULATION_HPP
#define __BASEMODULATION_HPP

#include "address.hpp"

#define DUMP_MODULATION_LENGTH 2

/*******************/
/* Base Modulation */
/*******************/
class BaseModulation {
private:
  bool _positivePhase; //control the phase
                       //+ : positive phase, - : negative phase
  unsigned char _LFOSelect; //control the number of the LFO
                           //1, 2, 3 respectively LFO-1, LFO-2, LFO-3
  unsigned char _LFODepth; //between 0 and 100

public:
  //constructor destructor
  BaseModulation();
  ~BaseModulation();

  //affect methods
  void setLFOPhase(bool p);
  void setLFOSelect(unsigned char ls);
  void setLFODepth(unsigned char ld);

  //access methods
  bool getLFOPhase();
  unsigned char getLFOSelect();
  unsigned char getLFODepth();

  //dump method
  void dump(Address& a, unsigned length, unsigned char* data);

  //print method
  void print(int m); //print the modulation on the std output tabulated of m
};

#endif
