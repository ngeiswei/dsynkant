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

#ifndef __DSYNKANT_SET_HPP
#define __DSYNKANT_SET_HPP

#include "bank.hpp"
#include <vector>

namespace dsynkant {

class Bank;

class Set {
private:
	std::string _setName;
	std::vector<Bank> _banks;

public:
	Set();
	Set(const std::string& sn);
	~Set();

	void addBank(const Bank& p);
	const Bank& getBank(unsigned index) const;
	Bank& getBank(unsigned index);

	void dump(unsigned length, const unsigned char* data);

	void print(int m = 0) const;
};

} // ~namespace dsynkant

#endif
