/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    commondef.cpp

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

#include "commondef.hpp"
#include <string.h>

using namespace dsynkant;

void ps(int s) {
	for(int i = 0; i < s; i++) printf(" ");
}

std::string FracKeyFollowStr(FracKeyFollow kf) {
	switch(kf) {
	case FracKeyFollow::minus1 : return minus1Str; break;
	case FracKeyFollow::minus1div2 : return minus1div2Str; break;
	case FracKeyFollow::minus1div4 : return minus1div4Str; break;
	case FracKeyFollow::zero : return zeroStr; break;
	case FracKeyFollow::plus1div8 : return plus1div8Str; break;
	case FracKeyFollow::plus1div4 : return plus1div4Str; break;
	case FracKeyFollow::plus3div8 : return plus3div8Str; break;
	case FracKeyFollow::plus1div2 : return plus1div2Str; break;
	case FracKeyFollow::plus5div8 : return plus5div8Str; break;
	case FracKeyFollow::plus3div4 : return plus3div4Str; break;
	case FracKeyFollow::plus7div8 : return plus7div8Str; break;
	case FracKeyFollow::plus1 : return plus1Str; break;
	case FracKeyFollow::plus5div4 : return plus5div4Str; break;
	case FracKeyFollow::plus3div2 : return plus3div2Str; break;
	case FracKeyFollow::plus2 : return plus2Str; break;
	case FracKeyFollow::s1 : return s1Str; break;
	case FracKeyFollow::s2 : return s2Str; break;
	default :
		printf("WG::keyFollowStr : %d impossible case\n", (int)kf);
		return NULL;
		break;
	}
}

char D50CharToASCII(unsigned char c) {
	if(c == 0) return 0x20;
	else if(c<27) return (char)(c-1+0x41);
	else if(c<53) return (char)(c-27+0x61);
	else if(c<63) return (char)(c-53+0x30);
	else if(c == 63) return '-';
	else return 0;
}
