/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    wg.hpp

    Copyleft (c) 2006 Nil Geisweiller

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

#ifndef __WG_HPP
#define __WG_HPP

#include "basemodulation.hpp"
#include "../commondef/commondef.hpp"
#include "address.hpp"

class BaseModulation;

#define DUMP_WG_LENGTH 0x0d

typedef enum {
  LMoff,
  LMplus,
  LMminus,
  LMAnL
} WGLFOMode;

#define offStr "off"
#define plusStr "plus"
#define minusStr "minus"
#define AnLStr "AnL"

typedef enum {
  PEMoff,
  PEMplus,
  PEMminus
} WGPEnvMode;

typedef enum {
  BMoff,
  BMkeyFollow,
  BMnormal
} WGBenderMode;

#define keyFollowStr "keyFollow"
#define normalStr "normal"

typedef enum {
  square,
  sawtooth
} WGWaveform;

#define squareStr "square"
#define sawtoothStr "sawtooth"

typedef enum {
  Marimba,
  Vibraphone,
  Xylophone_1,
  Xylophone_2,
  Log_Bass,
  Hammer,
  Japanese_Drum,
  Kalimba,
  Pluck_1,
  Chink,
  Agogo,
  Triangle,
  Bells,
  NailFile,
  Pick,
  Low_Piano,
  Mid_Piano,
  High_Piano,
  Harpsichord,
  Harp,
  Organ_Percussion,
  Steel_Strings,
  Nylon_Strings,
  Electric_Guitar_1,
  Electric_Guitar_2,
  Dirty_Guitar,
  Pick_Bass,
  Pop_Bass,
  Thump,
  Upright_Bass,
  Clarinet,
  Breath,
  Steamer,
  High_Flute,
  Low_Flute,
  Guiro,
  Indian_Flute,
  Flute_Harmonics,
  Lips_1,
  Lips_2,
  Trumpet,
  Trombones,
  Contrabass,
  Cello,
  Violon_Bow,
  Violins,
  Pizzicart,
  Draws_bars_Loop,
  High_Organ_Loop,
  Low_Organ_Loop,
  Electric_Piano_Loop_1,
  Electric_Piano_Loop_2,
  Clavi_Loop,
  Harpsichord_Loop,
  Electric_Bass_Loop_1,
  Acoustic_Bass_Loop,
  Electric_Bass_Loop_2,
  Electric_Bass_Loop_3,
  Electric_Guitar_Loop,
  Cello_Loop,
  Violin_Loop,
  Lead_Loop,
  Sax_Loop_1,
  Sax_Loop_2,
  Aah_Loop,
  Ooh_Loop,
  Male_Loop_1,
  Spectrum_1_Loop,
  Spectrum_2_Loop,
  Spectrum_3_Loop,
  Spectrum_4_Loop,
  Spectrum_5_Loop,
  Spectrum_6_Loop,
  Spectrum_7_Loop,
  Male_Loop_2,
  Noise_Loop,
  Loop_01,
  Loop_02,
  Loop_03,
  Loop_04,
  Loop_05,
  Loop_06,
  Loop_07,
  Loop_08,
  Loop_09,
  Loop_10,
  Loop_11,
  Loop_12,
  Loop_13,
  Loop_14,
  Loop_15,
  Loop_16,
  Loop_17,
  Loop_18,
  Loop_19,
  Loop_20,
  Loop_21,
  Loop_22,
  Loop_23,
  Loop_24
} WGPCMWaveNo;

#define Marimba_Str "Marimba"
#define Vibraphone_Str "Vibraphone"
#define Xylophone_1_Str "Xylophone 1"
#define Xylophone_2_Str "Xylophone 2"
#define Log_Bass_Str "Log Bass"
#define Hammer_Str "Hammer"
#define Japanese_Drum_Str "Japanese Drum"
#define Kalimba_Str "Kalimba"
#define Pluck_1_Str "Pluck 1"
#define Chink_Str "Chink"
#define Agogo_Str "Agogo"
#define Triangle_Str "Triangle"
#define Bells_Str "Bells"
#define Nail_File_Str "Nail File"
#define Pick_Str "Pick"
#define Low_Piano_Str "Low Piano"
#define Mid_Piano_Str "Mid Piano"
#define High_Piano_Str "High Piano"
#define Harpsichord_Str "Harpsichord"
#define Harp_Str "Harp"
#define Organ_Percussion_Str "Organ Percussion"
#define Steel_Strings_Str "Steel Strings"
#define Nylon_Strings_Str "Nylon Strings"
#define Electric_Guitar_1_Str "Electric Guitar 1"
#define Electric_Guitar_2_Str "Electric Guitar 2"
#define Dirty_Guitar_Str "Dirty Guitar"
#define Pick_Bass_Str "Pick Bass"
#define Pop_Bass_Str "Pop Bass"
#define Thump_Str "Thump"
#define Upright_Bass_Str "Upright Bass"
#define Clarinet_Str "Clarinet"
#define Breath_Str "Breath"
#define Steamer_Str "Steamer"
#define High_Flute_Str "High Flute"
#define Low_Flute_Str "Low Flute"
#define Guiro_Str "Guiro"
#define Indian_Flute_Str "Indian Flute"
#define Flute_Harmonics_Str "Flute Harmonics"
#define Lips_1_Str "Lips 1"
#define Lips_2_Str "Lips 2"
#define Trumpet_Str "Trumpet"
#define Trombones_Str "Trombones"
#define Contrabass_Str "Contrabass"
#define Cello_Str "Cello"
#define Violon_Bow_Str "Violon Bow"
#define Violins_Str "Violins"
#define Pizzicart_Str "Pizzicart"
#define Draws_bars_Loop_Str "Draws bars Loop"
#define High_Organ_Loop_Str "High Organ Loop"
#define Low_Organ_Loop_Str "Low Organ Loop"
#define Electric_Piano_Loop_1_Str "Electric Piano Loop 1"
#define Electric_Piano_Loop_2_Str "Electric Piano Loop 2"
#define Clavi_Loop_Str "Clavi Loop"
#define Harpsichord_Loop_Str "Harpsichord Loop"
#define Electric_Bass_Loop_1_Str "Electric_Bass Loop 1"
#define Acoustic_Bass_Loop_Str "Acoustic Bass Loop"
#define Electric_Bass_Loop_2_Str "Electric Bass Loop 2"
#define Electric_Bass_Loop_3_Str "Electric Bass Loop 3"
#define Electric_Guitar_Loop_Str "Electric Guitar Loop"
#define Cello_Loop_Str "Cello Loop"
#define Violin_Loop_Str "Violin Loop"
#define Lead_Loop_Str "Lead Loop"
#define Sax_Loop_1_Str "Sax Loop 1"
#define Sax_Loop_2_Str "Sax Loop 2"
#define Aah_Loop_Str "Aah Loop"
#define Ooh_Loop_Str "Ooh Loop"
#define Male_Loop_1_Str "Male Loop 1"
#define Spectrum_1_Loop_Str "Spectrum 1 Loop"
#define Spectrum_2_Loop_Str "Spectrum 2 Loop"
#define Spectrum_3_Loop_Str "Spectrum 3 Loop"
#define Spectrum_4_Loop_Str "Spectrum 4 Loop"
#define Spectrum_5_Loop_Str "Spectrum 5 Loop"
#define Spectrum_6_Loop_Str "Spectrum 6 Loop"
#define Spectrum_7_Loop_Str "Spectrum 7 Loop"
#define Male_Loop_2_Str "Male Loop 2"
#define Noise_Loop_Str "Noise Loop"
#define Loop_01_Str "Loop 01"
#define Loop_02_Str "Loop 02"
#define Loop_03_Str "Loop 03"
#define Loop_04_Str "Loop 04"
#define Loop_05_Str "Loop 05"
#define Loop_06_Str "Loop 06"
#define Loop_07_Str "Loop 07"
#define Loop_08_Str "Loop 08"
#define Loop_09_Str "Loop 09"
#define Loop_10_Str "Loop 10"
#define Loop_11_Str "Loop 11"
#define Loop_12_Str "Loop 12"
#define Loop_13_Str "Loop 13"
#define Loop_14_Str "Loop 14"
#define Loop_15_Str "Loop 15"
#define Loop_16_Str "Loop 16"
#define Loop_17_Str "Loop 17"
#define Loop_18_Str "Loop 18"
#define Loop_19_Str "Loop 19"
#define Loop_20_Str "Loop 20"
#define Loop_21_Str "Loop 21"
#define Loop_22_Str "Loop 22"
#define Loop_23_Str "Loop 23"
#define Loop_24_Str "Loop 24"

#define Marimba_Short_Str "Marmba"
#define Vibraphone_Short_Str "Vibes"
#define Xylophone_1_Short_Str "Xylo1"
#define Xylophone_2_Short_Str "Xylo2"
#define Log_Bass_Short_Str "Log_Bs"
#define Hammer_Short_Str "Hammer"
#define Japanese_Drum_Short_Str "JpnDrm"
#define Kalimba_Short_Str "Kalmba"
#define Pluck_1_Short_Str "Pluck1"
#define Chink_Short_Str "Chink"
#define Agogo_Short_Str "Agogo"
#define Triangle_Short_Str "3angle"
#define Bells_Short_Str "Bells"
#define Nail_File_Short_Str "Nails"
#define Pick_Short_Str "Pick"
#define Low_Piano_Short_Str "LPiano"
#define Mid_Piano_Short_Str "MPiano"
#define High_Piano_Short_Str "HPiano"
#define Harpsichord_Short_Str "Harpsi"
#define Harp_Short_Str "Harp"
#define Organ_Percussion_Short_Str "Orgprc"
#define Steel_Strings_Short_Str "Steel"
#define Nylon_Strings_Short_Str "Nylon"
#define Electric_Guitar_1_Short_Str "Eguit1"
#define Electric_Guitar_2_Short_Str "Eguit2"
#define Dirty_Guitar_Short_Str "Dirt"
#define Pick_Bass_Short_Str "P_Bass"
#define Pop_Bass_Short_Str "Pop"
#define Thump_Short_Str "Thump"
#define Upright_Bass_Short_Str "Uprit"
#define Clarinet_Short_Str "Clarnt"
#define Breath_Short_Str "Breath"
#define Steamer_Short_Str "Steam"
#define High_Flute_Short_Str "FluteH"
#define Low_Flute_Short_Str "FluteL"
#define Guiro_Short_Str "Guiro"
#define Indian_Flute_Short_Str "IndFlt"
#define Flute_Harmonics_Short_Str "Harmo"
#define Lips_1_Short_Str "Lips1"
#define Lips_2_Short_Str "Lips2"
#define Trumpet_Short_Str "Trumpt"
#define Trombones_Short_Str "Bones"
#define Contrabass_Short_Str "Contra"
#define Cello_Short_Str "Cello"
#define Violon_Bow_Short_Str "VioBow"
#define Violins_Short_Str "Violns"
#define Pizzicart_Short_Str "Pizz"
#define Draws_bars_Loop_Short_Str "Drawbr"
#define High_Organ_Loop_Short_Str "Horgan"
#define Low_Organ_Loop_Short_Str "Lorgan"
#define Electric_Piano_Loop_1_Short_Str "EP_lp1"
#define Electric_Piano_Loop_2_Short_Str "EP_lp2"
#define Clavi_Loop_Short_Str "CLAVlp"
#define Harpsichord_Loop_Short_Str "HC_lp"
#define Electric_Bass_Loop_1_Short_Str "EB_lp1"
#define Acoustic_Bass_Loop_Short_Str "AB_lp"
#define Electric_Bass_Loop_2_Short_Str "EB_lp2"
#define Electric_Bass_Loop_3_Short_Str "EB_lp3"
#define Electric_Guitar_Loop_Short_Str "EG_lp"
#define Cello_Loop_Short_Str "CELLlp"
#define Violin_Loop_Short_Str "VIOLlp"
#define Lead_Loop_Short_Str "Reedlp"
#define Sax_Loop_1_Short_Str "SAXlp1"
#define Sax_Loop_2_Short_Str "SAXlp2"
#define Aah_Loop_Short_Str "Aah_lp"
#define Ooh_Loop_Short_Str "Ooh_lp"
#define Male_Loop_1_Short_Str "Manlp1"
#define Spectrum_1_Loop_Short_Str "Spect1"
#define Spectrum_2_Loop_Short_Str "Spect2"
#define Spectrum_3_Loop_Short_Str "Spect3"
#define Spectrum_4_Loop_Short_Str "Spect4"
#define Spectrum_5_Loop_Short_Str "Spect5"
#define Spectrum_6_Loop_Short_Str "Spect6"
#define Spectrum_7_Loop_Short_Str "Spect7"
#define Male_Loop_2_Short_Str "Manlp2"
#define Noise_Loop_Short_Str "Noise"
#define Loop_01_Short_Str "Loop01"
#define Loop_02_Short_Str "Loop02"
#define Loop_03_Short_Str "Loop03"
#define Loop_04_Short_Str "Loop04"
#define Loop_05_Short_Str "Loop05"
#define Loop_06_Short_Str "Loop06"
#define Loop_07_Short_Str "Loop07"
#define Loop_08_Short_Str "Loop08"
#define Loop_09_Short_Str "Loop09"
#define Loop_10_Short_Str "Loop10"
#define Loop_11_Short_Str "Loop11"
#define Loop_12_Short_Str "Loop12"
#define Loop_13_Short_Str "Loop13"
#define Loop_14_Short_Str "Loop14"
#define Loop_15_Short_Str "Loop15"
#define Loop_16_Short_Str "Loop16"
#define Loop_17_Short_Str "Loop17"
#define Loop_18_Short_Str "Loop18"
#define Loop_19_Short_Str "Loop19"
#define Loop_20_Short_Str "Loop20"
#define Loop_21_Short_Str "Loop21"
#define Loop_22_Short_Str "Loop22"
#define Loop_23_Short_Str "Loop23"
#define Loop_24_Short_Str "Loop24"


/******************/
/* Wave Generator */
/******************/
class WG : public BaseModulation {
private:
  unsigned char _pitchCoarse; //between C1 and C7, C4 is the middle
  char _pitchFine; //between -50 and +50
  FracKeyFollow _keyFollow;
  WGLFOMode _LFOMode;
  WGPEnvMode _PEnvMode;
  WGBenderMode _benderMode;
  WGWaveform _waveform;
  WGPCMWaveNo _PCMWaveNo;
  unsigned char _pulseWidth; //between 0 and 100
  char _velocityRange; //between -7 and +7
  char _aftertouchRange; //between -7 and +7

public:
  //Constructor destructor
  WG();
  ~WG();

  //affect methods
  void setPitchCoarse(unsigned char pc);
  void setPitchFine(char pf);
  void setLFOMode(WGLFOMode lm);
  void setPEnvMode(WGPEnvMode pm);
  void setBenderMode(WGBenderMode bm);
  void setWaveform(WGWaveform wf);
  void setPCMWaveNo(WGPCMWaveNo pwn);
  void setPulseWidth(unsigned char pw);
  void setVelocityRange(char vr);
  void setAftertouchRange(char ar);

  //access methods
  unsigned char getPitchCoarse();
  char getPitchFine();
  WGLFOMode getLFOMode();
  WGPEnvMode getPEnvMode();
  WGBenderMode getBenderMode();
  WGWaveform getWaveform();
  WGPCMWaveNo getPCMWaveNo();
  unsigned char getPulseWidth();
  char getVelocityRange();
  char getAftertouchRange();

  //dump method
  void dump(Address& a, unsigned length, unsigned char* data);

  //print and string method
  char* fracKeyFollowStr();
  char* LFOModeStr(WGLFOMode lm);
  char* LFOModeStr();
  char* PEnvModeStr(WGPEnvMode pem);
  char* PEnvModeStr();
  char* benderModeStr(WGBenderMode bm);
  char* benderModeStr();
  char* waveformStr(WGWaveform wf);
  char* waveformStr();
  char* PCMWaveNoShortStr(WGPCMWaveNo pwn);
  char* PCMWaveNoShortStr();
  char* PCMWaveNoStr(WGPCMWaveNo pwn);
  char* PCMWaveNoStr();
  void print(int m); //print the WG with a margine m
};


#endif
