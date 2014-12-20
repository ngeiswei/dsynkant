/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    patch.hpp

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

#ifndef __PATCH_HPP
#define __PATCH_HPP

#include "partial.hpp"
#include "common.hpp"
#include "patchparameter.hpp"
#include "address.hpp"

class Partial;
class Common;
class PatchParameter;

class Patch {
private:
  Partial* _upperPartial1;
  Partial* _upperPartial2;
  Common* _upperCommon;
  Partial* _lowerPartial1;
  Partial* _lowerPartial2;
  Common* _lowerCommon;
  PatchParameter* _patchParameter;

public:
  //constructor destructor
  Patch();
  ~Patch();

  //dump method
  void dump(Address& a, unsigned length, unsigned char* data);

  //print method
  void print(int m = 0);
};

#endif
