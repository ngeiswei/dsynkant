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

const std::string minus1Str="-1";
const std::string minus1div2Str="-1/2";
const std::string minus1div4Str="-1/4";
const std::string zeroStr="0";
const std::string plus1div8Str="1/8";
const std::string plus1div4Str="1/4";
const std::string plus3div8Str="3/8";
const std::string plus1div2Str="1/2";
const std::string plus5div8Str="5/8";
const std::string plus3div4Str="3/4";
const std::string plus7div8Str="7/8";
const std::string plus1Str="1";
const std::string plus5div4Str="5/4";
const std::string plus3div2Str="3/2";
const std::string plus2Str="2";
const std::string s1Str="s1";
const std::string s2Str="s2";

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

void ps(int n); //printf n space

std::string FracKeyFollowStr(FracKeyFollow kf);

char D50CharToASCII(unsigned char c);

} // ~namespace dsynkant

#endif
