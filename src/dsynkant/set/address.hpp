/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    address.hpp

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

#ifndef __ADDRESS_HPP
#define __ADDRESS_HPP

class Address {
private:
	int _aa;
	int _bb;
	int _cc;
public:
	Address();
	Address(int cc);
	Address(int bb, int cc);
	Address(int aa, int bb, int cc);
	Address(const Address& a);
	~Address();

	void operator=(const Address& a);
	void operator+=(int i);
	void operator+=(const Address& a);
	void operator-=(const Address& a);
	void operator-=(int i);
	void operator++();
  
	Address& operator-(const Address& a) const;

	bool operator>=(const Address& a) const;
	bool operator>(const Address& a) const;
	bool operator<(const Address& a) const;
	bool operator<=(const Address& a) const;
	bool operator==(const Address& a) const;
	bool operator!=(const Address& a) const;

	int toInt() const;
	char* toStr() const;
};

#endif
