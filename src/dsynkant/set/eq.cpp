/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    eq.cpp

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

#include "eq.hpp"
#include "../commondef/commondef.hpp"

//Constructor destructor
EQ::EQ() {
	_Lf = lf150;
	_Lg = 0; // Most likely
	_Hf = hf1000;
	_HQ = hq0_3;
	_Hg = 0; // Most likely
}

EQ::~EQ() {}

void EQ::setLf(EQLowFreq Lf) {
	_Lf = Lf;
}
void EQ::setLg(char Lg) {
	_Lg = Lg;
}
void EQ::setHf(EQHighFreq Hf) {
	_Hf = Hf;
}
void EQ::setHQ(EQHighQ HQ) {
	_HQ = HQ;
}
void EQ::setHg(char Hg) {
	_Hg = Hg;
}

EQLowFreq EQ::getLf() const {
	return _Lf;
}
char EQ::getLg() const {
	return _Lg;
}
EQHighFreq EQ::getHf() const {
	return _Hf;
}
EQHighQ EQ::getHQ() const {
	return _HQ;
}
char EQ::getHg() const {
	return _Hg;
}

void EQ::dump(Address& a, unsigned length, const unsigned char* data) {
	Address cura;
	unsigned index = 0;
	if(length > index && a == cura) {
		_Lf = (EQLowFreq)data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_Lg = (char)data[index] - 12;
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_Hf = (EQHighFreq)data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_HQ = (EQHighQ)data[index];
		index++;
		++a;
	}
	++cura;
	if(length > index && a == cura) {
		_Hg = (char)data[index] - 12;
		++a;
	}
}

float EQ::LowFreqFloat(EQLowFreq lf) const {
	switch(lf) {
	case lf63 : return lf63_f; break;
	case lf75 : return lf75_f; break;
	case lf88 : return lf88_f; break;
	case lf105 : return lf105_f; break;
	case lf125 : return lf125_f; break;
	case lf150 : return lf150_f; break;
	case lf175 : return lf175_f; break;
	case lf210 : return lf210_f; break;
	case lf250 : return lf250_f; break;
	case lf300 : return lf300_f; break;
	case lf350 : return lf350_f; break;
	case lf420 : return lf420_f; break;
	case lf500 : return lf500_f; break;
	case lf600 : return lf600_f; break;
	case lf700 : return lf700_f; break;
	case lf840 : return lf840_f; break;
	default :
		return 0.0;
		printf("EQ::LowFreqFloat : impossible case\n");
		break;
	}
}
float EQ::LowFreqFloat() const {
	return LowFreqFloat(_Lf);
}
float EQ::HighFreqFloat(EQHighFreq hf) const {
	switch(hf) {
	case hf250 : return hf250_f; break;
	case hf300 : return hf300_f; break;
	case hf350 : return hf350_f; break;
	case hf420 : return hf420_f; break;
	case hf500 : return hf500_f; break;
	case hf600 : return hf600_f; break;
	case hf700 : return hf700_f; break;
	case hf840 : return hf840_f; break;
	case hf1000 : return hf1000_f; break;
	case hf1200 : return hf1200_f; break;
	case hf1400 : return hf1400_f; break;
	case hf1700 : return hf1700_f; break;
	case hf2000 : return hf2000_f; break;
	case hf2400 : return hf2400_f; break;
	case hf2800 : return hf2800_f; break;
	case hf3400 : return hf3400_f; break;
	case hf4000 : return hf4000_f; break;
	case hf4800 : return hf4800_f; break;
	case hf5700 : return hf5700_f; break;
	case hf6700 : return hf6700_f; break;
	case hf8000 : return hf8000_f; break;
	case hf9500 : return hf9500_f; break;
	default :
		printf("EQ::HighFreqFloat : impossible case\n");
		return 0.0;
		break;
	}
}
float EQ::HighFreqFloat() const {
	return HighFreqFloat(_Hf);
}
float EQ::HighQFloat(EQHighQ hq) const {
	switch(hq) {
	case hq0_3 : return hq0_3_f; break;
	case hq0_5 : return hq0_5_f; break;
	case hq0_7 : return hq0_7_f; break;
	case hq1_0 : return hq1_0_f; break;
	case hq1_4 : return hq1_4_f; break;
	case hq2_0 : return hq2_0_f; break;
	case hq3_0 : return hq3_0_f; break;
	case hq4_2 : return hq4_2_f; break;
	case hq6_0 : return hq6_0_f; break;
	default :
		printf("EQ::HighQFloat : impossible case\n");
		return 0.0;
		break;
	}
}
float EQ::HighQFloat() const {
	return HighQFloat(_HQ);
}
void EQ::print(int m) const {
	ps(m);
	printf("Eq = (Lf : %f, Lg : %d, Hf : %f, HQ : %f, Hg : %d)\n",
	       LowFreqFloat(), _Lg, HighFreqFloat(), HighQFloat(), _Hg);
}
