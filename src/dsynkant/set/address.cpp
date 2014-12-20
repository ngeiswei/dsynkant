/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    patch.cpp

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

#include "address.hpp"
#include <stdio.h>
#include <stdlib.h>

Address::Address() {
  _aa = 0;
  _bb = 0;
  _cc = 0;
}
Address::Address(int cc) {
  _aa = 00;
  _bb = 00;
  _cc = cc;
}
Address::Address(int bb, int cc) {
  _aa = 00;
  _bb = bb;
  _cc = cc;
}
Address::Address(int aa, int bb, int cc) {
  _aa = aa;
  _bb = bb;
  _cc = cc;
}
Address::Address(const Address& a) {
  _aa = a._aa;
  _bb = a._bb;
  _cc = a._cc;
}
Address::~Address() {
}

void Address::operator=(const Address& a) {
  _aa = a._aa;
  _bb = a._bb;
  _cc = a._cc;
}

void Address::operator+=(const Address& a) {
  _cc += a._cc;
  if(_cc > 0x7f) {
    _cc -= 0x80;
    _bb++;
  }
  _bb += a._bb;
  if(_bb > 0x7f) {
    _bb -= 0x80;
    _aa++;
  }
  _aa += a._aa;
}
void Address::operator+=(int i) {
  operator+=(Address(i));
}
void Address::operator-=(const Address& a) {
  _cc -= a._cc;
  if(_cc < 0) {
    _cc += 0x80;
    _bb--;
  }
  _bb -= a._bb;
  if(_bb < 0) {
    _bb += 0x80;
    _aa--;
  }
  _aa -= a._aa;
}
void Address::operator-=(int i) {
  operator-=(Address(i));
}

void Address::operator++() {
  operator+=(1);
}

Address& Address::operator-(const Address& a) const {
  Address* res = new Address(*this);
  *res -= a;
  return *res;
}

bool Address::operator>=(const Address& a) const {
  return operator>(a) || operator==(a);
}
bool Address::operator>(const Address& a) const {
  return ((_aa > a._aa) 
	  || (_aa==a._aa && _bb > a._bb)
	  || (_bb==a._bb && _cc > a._cc));
}
bool Address::operator<(const Address& a) const {
  return ((_aa < a._aa) 
	  || (_aa==a._aa && _bb < a._bb)
	  || (_bb==a._bb && _cc < a._cc));
}
bool Address::operator<=(const Address& a) const {
  return operator<(a) || operator==(a);
}
bool Address::operator==(const Address& a) const {
  return _aa==a._aa && _bb==a._bb && _cc==a._cc;
}
bool Address::operator!=(const Address& a) const {
  return _aa!=a._aa || _bb!=a._bb || _cc!=a._cc;
}

int Address::toInt() const {
  return _aa*0x40*0x40 + _bb*0x40 + _cc;
}
char* Address::toStr() const {
  char* res = (char*) malloc(sizeof(char)*64);
  sprintf(res, "(%x:%x:%x)", _aa, _bb, _cc);
  return res;
}
