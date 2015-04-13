/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    commondef.hpp

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

#ifndef __DSYNKANT_COMMONDEF_HPP
#define __DSYNKANT_COMMONDEF_HPP

#include <stdio.h>
#include <string>

namespace dsynkant {

static const std::string minus1Str="-1";
static const std::string minus1div2Str="-1/2";
static const std::string minus1div4Str="-1/4";
static const std::string zeroStr="0";
static const std::string plus1div8Str="1/8";
static const std::string plus1div4Str="1/4";
static const std::string plus3div8Str="3/8";
static const std::string plus1div2Str="1/2";
static const std::string plus5div8Str="5/8";
static const std::string plus3div4Str="3/4";
static const std::string plus7div8Str="7/8";
static const std::string plus1Str="1";
static const std::string plus5div4Str="5/4";
static const std::string plus3div2Str="3/2";
static const std::string plus2Str="2";
static const std::string s1Str="s1";
static const std::string s2Str="s2";

enum class FracKeyFollow {
	minus1,
	minus1div2,
	minus1div4,
	zero,
	plus1div8,
	plus1div4,
	plus3div8,
	plus1div2,
	plus5div8,
	plus3div4,
	plus7div8,
	plus1,
	plus5div4,
	plus3div2,
	plus2,
	s1,
	s2
};

static void ps(int s) {
	for(int i = 0; i < s; i++) printf(" ");
}

static std::string FracKeyFollowStr(FracKeyFollow kf) {
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

static char D50CharToASCII(unsigned char c) {
	if(c == 0) return 0x20;
	else if(c<27) return (char)(c-1+0x41);
	else if(c<53) return (char)(c-27+0x61);
	else if(c<63) return (char)(c-53+0x30);
	else if(c == 63) return '-';
	else return 0;
}

} // ~namespace dsynkant

#endif
