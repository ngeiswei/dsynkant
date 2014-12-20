/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    eq.hpp

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

#ifndef __EQ_HPP
#define __EQ_HPP

#include "address.hpp"

#define DUMP_EQ_LENGTH 5

#define lf63_f 63.0
#define lf75_f 75.0
#define lf88_f 88.0
#define lf105_f 105.0
#define lf125_f 125.0
#define lf150_f 150.0
#define lf175_f 175.0
#define lf210_f 210.0
#define lf250_f 250.0
#define lf300_f 300.0
#define lf350_f 350.0
#define lf420_f 420.0
#define lf500_f 500.0
#define lf600_f 600.0
#define lf700_f 700.0
#define lf840_f 840.0

typedef enum {
  lf63,
  lf75,
  lf88,
  lf105,
  lf125,
  lf150,
  lf175,
  lf210,
  lf250,
  lf300,
  lf350,
  lf420,
  lf500,
  lf600,
  lf700,
  lf840
} EQLowFreq;

#define hf250_f 250.0
#define hf300_f 300.0
#define hf350_f 350.0
#define hf420_f 420.0
#define hf500_f 500.0
#define hf600_f 600.0
#define hf700_f 700.0
#define hf840_f 840.0
#define hf1000_f 1000.0
#define hf1200_f 1200.0
#define hf1400_f 1400.0
#define hf1700_f 1700.0
#define hf2000_f 2000.0
#define hf2400_f 2400.0
#define hf2800_f 2800.0
#define hf3400_f 3400.0
#define hf4000_f 4000.0
#define hf4800_f 4800.0
#define hf5700_f 5700.0
#define hf6700_f 6700.0
#define hf8000_f 8000.0
#define hf9500_f 9500.0

typedef enum {
  hf250,
  hf300,
  hf350,
  hf420,
  hf500,
  hf600,
  hf700,
  hf840,
  hf1000,
  hf1200,
  hf1400,
  hf1700,
  hf2000,
  hf2400,
  hf2800,
  hf3400,
  hf4000,
  hf4800,
  hf5700,
  hf6700,
  hf8000,
  hf9500
} EQHighFreq;

#define hq0_3_f 0.3
#define hq0_5_f 0.5
#define hq0_7_f 0.7
#define hq1_0_f 1.0
#define hq1_4_f 1.4
#define hq2_0_f 2.0
#define hq3_0_f 3.0
#define hq4_2_f 4.2
#define hq6_0_f 6.0

typedef enum {
  hq0_3,
  hq0_5,
  hq0_7,
  hq1_0,
  hq1_4,
  hq2_0,
  hq3_0,
  hq4_2,
  hq6_0
} EQHighQ;

class EQ {
private:
  EQLowFreq _Lf;
  char _Lg; //between -12 and +12 (in dB)
  EQHighFreq _Hf;
  EQHighQ _HQ;
  char _Hg; //between -12 and +12 (in dB)  
  
public:
  EQ();
  ~EQ();
  
  //affect methods
  void setLf(EQLowFreq Lf);
  void setLg(char Lg);
  void setHf(EQHighFreq Hf);
  void setHQ(EQHighQ HQ);
  void setHg(char Hg);  

  //dump method
  void dump(Address& a, unsigned length, unsigned char* data);

  //access methods
  EQLowFreq getLf();
  char getLg();
  EQHighFreq getHf();
  EQHighQ getHQ();
  char getHg();  

  //print and float methods
  float LowFreqFloat(EQLowFreq lf);
  float LowFreqFloat();
  float HighFreqFloat(EQHighFreq hf);
  float HighFreqFloat();
  float HighQFloat(EQHighQ hq);
  float HighQFloat();
  void print(int m);
};

#endif
