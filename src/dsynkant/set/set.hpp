/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    set.hpp

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

#ifndef __SET_HPP
#define __SET_HPP

#include "bank.hpp"
#include <vector>

class Bank;

class Set {
private:
    char* _setName;
    std::vector<Bank*> _banks;

public:
    Set();
    Set(char* sn);
    ~Set();

    void addBank(Bank* p);
    Bank* getBank(unsigned index);

    void dump(unsigned length, unsigned char* data);

    void print(int m = 0);
};

#endif
