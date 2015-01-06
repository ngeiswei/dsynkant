/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    partial.cpp

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

#include "partial.hpp"

//constructor desturctor
Partial::Partial() {}

Partial::~Partial() {}

//bump method
void Partial::dump(Address& a, unsigned length, const unsigned char* data) {
    Address lowBound(0, 0);
    Address upBound(0, DUMP_PARTIAL_LENGTH);
    unsigned index = 0;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound; //local address
        Address prela = la; //to keep before the dump
        _wg.dump(la, length, data);
        Address diffa = la - prela; //distance made by dump
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_WG_LENGTH;
    upBound += DUMP_TVF_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound; //local address
        Address prela = la; //to keep before the dump
        _tvf.dump(la, length - index, &data[index]);
        Address diffa = la - prela; //distance made by dump
        index += diffa.toInt();
        a += diffa;
    }
    lowBound += DUMP_TVF_LENGTH;
    upBound += DUMP_TVA_LENGTH;
    if(length > index && a >= lowBound && a < upBound) {
        Address la = a - lowBound; //local address
        Address prela = la; //to keep before the dump
        _tva.dump(la, length - index, &data[index]);
        Address last(DUMP_PARTIAL_LENGTH);
        a = DUMP_PARTIAL_LENGTH;
    }
}

void Partial::print(int m) const {
    ps(m);
    printf("Wave Generator :\n");
    _wg.print(m+2);
    ps(m);
    printf("Time Variant Filter :\n");
    _tvf.print(m+2);
    ps(m);
    printf("Time Variant Amplitude :\n");
    _tva.print(m+2);
}
