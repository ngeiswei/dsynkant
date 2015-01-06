/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    partial.hpp

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

#ifndef __PARTIAL_HPP
#define __PARTIAL_HPP

#include "wg.hpp"
#include "tvf.hpp"
#include "tva.hpp"

#define DUMP_PARTIAL_LENGTH 0x40

class Partial {
private:
    WG _wg;
    TVF _tvf;
    TVA _tva;
  
public:
    Partial();
    ~Partial();

    void dump(Address& a, unsigned length, const unsigned char* data);

    void print(int m) const;
};

#endif
