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

#ifndef __COMMONDEF_HPP
#define __COMMONDEF_HPP

#include <stdio.h>

#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

#define minus1Str "-1"
#define minus1div2Str "-1/2"
#define minus1div4Str "-1/4"
#define zeroStr "0"
#define plus1div8Str "1/8"
#define plus1div4Str "1/4"
#define plus3div8Str "3/8"
#define plus1div2Str "1/2"
#define plus5div8Str "5/8"
#define plus3div4Str "3/4"
#define plus7div8Str "7/8"
#define plus1Str "1"
#define plus5div4Str "5/4"
#define plus3div2Str "3/2"
#define plus2Str "2"
#define s1Str "s1"
#define s2Str "s2"

typedef enum {
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
} FracKeyFollow;

void ps(int n); //printf n space

char* FracKeyFollowStr(FracKeyFollow kf);

char D50CharToASCII(unsigned char c);

#endif
