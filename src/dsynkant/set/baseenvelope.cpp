/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    baseenvelope.cpp

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

#include "baseenvelope.hpp"
#include "../commondef/commondef.hpp"

using namespace dsynkant;

/**************************/
/* Constructor destructor */
/**************************/
BaseEnvelope::BaseEnvelope() {
	_time1 = 0;
	_level1 = 100;
	_time2 = 50;
	_level2 = 100;
	_time3 = 50;
	_level3 = 100;
	_time4 = 50;
	_sustainLevel = 100;
	_time5 = 50;
	_endLevel = 0;
}
BaseEnvelope::~BaseEnvelope() {
}

/******************/
/* Affect methods */
/******************/
void BaseEnvelope::setTime1(unsigned char t1) {
	_time1 = t1;
}
void BaseEnvelope::setLevel1(unsigned char l1) {
	_level1 = l1;
}
void BaseEnvelope::setTime2(unsigned char t2) {
	_time2 = t2;
}
void BaseEnvelope::setLevel2(unsigned char l2) {
	_level2 = l2;
}
void BaseEnvelope::setTime3(unsigned char t3) {
	_time3 = t3;
}
void BaseEnvelope::setLevel3(unsigned char l3) {
	_level3 = l3;
}
void BaseEnvelope::setTime4(unsigned char t4) {
	_time4 = t4;
}
void BaseEnvelope::setSustainLevel(unsigned char sl) {
	_sustainLevel = sl;
}
void BaseEnvelope::setTime5(unsigned char t5) {
	_time5 = t5;
}
void BaseEnvelope::setEndLevel(unsigned char el) {
	_endLevel = el;
}

/******************/
/* Access methods */
/******************/
unsigned char BaseEnvelope::getTime1() const {
	return _time1;
}
unsigned char BaseEnvelope::getLevel1() const {
	return _level1;
}
unsigned char BaseEnvelope::getTime2() const {
	return _time2;
}
unsigned char BaseEnvelope::getLevel2() const {
	return _level2;
}
unsigned char BaseEnvelope::getTime3() const {
	return _time3;
}
unsigned char BaseEnvelope::getLevel3() const {
	return _level3;
}
unsigned char BaseEnvelope::getTime4() const {
	return _time4;
}
unsigned char BaseEnvelope::getSustainLevel() const {
	return _sustainLevel;
}
unsigned char BaseEnvelope::getTime5() const {
	return _time5;
}
unsigned char BaseEnvelope::getEndLevel() const {
	return _endLevel;
}

void BaseEnvelope::dump(Address& a, unsigned length, const unsigned char* data) {
	Address cura; //current address
	unsigned index = 0;
	if(length > index && a == cura) {
		_time1 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_time2 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_time3 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_time4 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_time5 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_level1 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_level2 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_level3 = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_sustainLevel = data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_endLevel = data[index];
		++a;
	}
}

void BaseEnvelope::print(int m) const {
	ps(m);
	printf("Envelope = " 
	       "(T1:%d,L1:%d,T2:%d,L2:%d,T3:%d,L3:%d,T4:%d,SL:%d,T5:%d,EL:%d)\n",
	       _time1, _level1, _time2, _level2, _time3, _level3, _time4,
	       _sustainLevel, _time5, _endLevel);
}
