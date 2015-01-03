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

enum class WGPCMWaveNo {
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
};

const std::string Marimba_Str="Marimba";
const std::string Vibraphone_Str="Vibraphone";
const std::string Xylophone_1_Str="Xylophone 1";
const std::string Xylophone_2_Str="Xylophone 2";
const std::string Log_Bass_Str="Log Bass";
const std::string Hammer_Str="Hammer";
const std::string Japanese_Drum_Str="Japanese Drum";
const std::string Kalimba_Str="Kalimba";
const std::string Pluck_1_Str="Pluck 1";
const std::string Chink_Str="Chink";
const std::string Agogo_Str="Agogo";
const std::string Triangle_Str="Triangle";
const std::string Bells_Str="Bells";
const std::string Nail_File_Str="Nail File";
const std::string Pick_Str="Pick";
const std::string Low_Piano_Str="Low Piano";
const std::string Mid_Piano_Str="Mid Piano";
const std::string High_Piano_Str="High Piano";
const std::string Harpsichord_Str="Harpsichord";
const std::string Harp_Str="Harp";
const std::string Organ_Percussion_Str="Organ Percussion";
const std::string Steel_Strings_Str="Steel Strings";
const std::string Nylon_Strings_Str="Nylon Strings";
const std::string Electric_Guitar_1_Str="Electric Guitar 1";
const std::string Electric_Guitar_2_Str="Electric Guitar 2";
const std::string Dirty_Guitar_Str="Dirty Guitar";
const std::string Pick_Bass_Str="Pick Bass";
const std::string Pop_Bass_Str="Pop Bass";
const std::string Thump_Str="Thump";
const std::string Upright_Bass_Str="Upright Bass";
const std::string Clarinet_Str="Clarinet";
const std::string Breath_Str="Breath";
const std::string Steamer_Str="Steamer";
const std::string High_Flute_Str="High Flute";
const std::string Low_Flute_Str="Low Flute";
const std::string Guiro_Str="Guiro";
const std::string Indian_Flute_Str="Indian Flute";
const std::string Flute_Harmonics_Str="Flute Harmonics";
const std::string Lips_1_Str="Lips 1";
const std::string Lips_2_Str="Lips 2";
const std::string Trumpet_Str="Trumpet";
const std::string Trombones_Str="Trombones";
const std::string Contrabass_Str="Contrabass";
const std::string Cello_Str="Cello";
const std::string Violon_Bow_Str="Violon Bow";
const std::string Violins_Str="Violins";
const std::string Pizzicart_Str="Pizzicart";
const std::string Draws_bars_Loop_Str="Draws bars Loop";
const std::string High_Organ_Loop_Str="High Organ Loop";
const std::string Low_Organ_Loop_Str="Low Organ Loop";
const std::string Electric_Piano_Loop_1_Str="Electric Piano Loop 1";
const std::string Electric_Piano_Loop_2_Str="Electric Piano Loop 2";
const std::string Clavi_Loop_Str="Clavi Loop";
const std::string Harpsichord_Loop_Str="Harpsichord Loop";
const std::string Electric_Bass_Loop_1_Str="Electric_Bass Loop 1";
const std::string Acoustic_Bass_Loop_Str="Acoustic Bass Loop";
const std::string Electric_Bass_Loop_2_Str="Electric Bass Loop 2";
const std::string Electric_Bass_Loop_3_Str="Electric Bass Loop 3";
const std::string Electric_Guitar_Loop_Str="Electric Guitar Loop";
const std::string Cello_Loop_Str="Cello Loop";
const std::string Violin_Loop_Str="Violin Loop";
const std::string Lead_Loop_Str="Lead Loop";
const std::string Sax_Loop_1_Str="Sax Loop 1";
const std::string Sax_Loop_2_Str="Sax Loop 2";
const std::string Aah_Loop_Str="Aah Loop";
const std::string Ooh_Loop_Str="Ooh Loop";
const std::string Male_Loop_1_Str="Male Loop 1";
const std::string Spectrum_1_Loop_Str="Spectrum 1 Loop";
const std::string Spectrum_2_Loop_Str="Spectrum 2 Loop";
const std::string Spectrum_3_Loop_Str="Spectrum 3 Loop";
const std::string Spectrum_4_Loop_Str="Spectrum 4 Loop";
const std::string Spectrum_5_Loop_Str="Spectrum 5 Loop";
const std::string Spectrum_6_Loop_Str="Spectrum 6 Loop";
const std::string Spectrum_7_Loop_Str="Spectrum 7 Loop";
const std::string Male_Loop_2_Str="Male Loop 2";
const std::string Noise_Loop_Str="Noise Loop";
const std::string Loop_01_Str="Loop 01";
const std::string Loop_02_Str="Loop 02";
const std::string Loop_03_Str="Loop 03";
const std::string Loop_04_Str="Loop 04";
const std::string Loop_05_Str="Loop 05";
const std::string Loop_06_Str="Loop 06";
const std::string Loop_07_Str="Loop 07";
const std::string Loop_08_Str="Loop 08";
const std::string Loop_09_Str="Loop 09";
const std::string Loop_10_Str="Loop 10";
const std::string Loop_11_Str="Loop 11";
const std::string Loop_12_Str="Loop 12";
const std::string Loop_13_Str="Loop 13";
const std::string Loop_14_Str="Loop 14";
const std::string Loop_15_Str="Loop 15";
const std::string Loop_16_Str="Loop 16";
const std::string Loop_17_Str="Loop 17";
const std::string Loop_18_Str="Loop 18";
const std::string Loop_19_Str="Loop 19";
const std::string Loop_20_Str="Loop 20";
const std::string Loop_21_Str="Loop 21";
const std::string Loop_22_Str="Loop 22";
const std::string Loop_23_Str="Loop 23";
const std::string Loop_24_Str="Loop 24";

const std::string Marimba_Short_Str="Marmba";
const std::string Vibraphone_Short_Str="Vibes";
const std::string Xylophone_1_Short_Str="Xylo1";
const std::string Xylophone_2_Short_Str="Xylo2";
const std::string Log_Bass_Short_Str="Log_Bs";
const std::string Hammer_Short_Str="Hammer";
const std::string Japanese_Drum_Short_Str="JpnDrm";
const std::string Kalimba_Short_Str="Kalmba";
const std::string Pluck_1_Short_Str="Pluck1";
const std::string Chink_Short_Str="Chink";
const std::string Agogo_Short_Str="Agogo";
const std::string Triangle_Short_Str="3angle";
const std::string Bells_Short_Str="Bells";
const std::string Nail_File_Short_Str="Nails";
const std::string Pick_Short_Str="Pick";
const std::string Low_Piano_Short_Str="LPiano";
const std::string Mid_Piano_Short_Str="MPiano";
const std::string High_Piano_Short_Str="HPiano";
const std::string Harpsichord_Short_Str="Harpsi";
const std::string Harp_Short_Str="Harp";
const std::string Organ_Percussion_Short_Str="Orgprc";
const std::string Steel_Strings_Short_Str="Steel";
const std::string Nylon_Strings_Short_Str="Nylon";
const std::string Electric_Guitar_1_Short_Str="Eguit1";
const std::string Electric_Guitar_2_Short_Str="Eguit2";
const std::string Dirty_Guitar_Short_Str="Dirt";
const std::string Pick_Bass_Short_Str="P_Bass";
const std::string Pop_Bass_Short_Str="Pop";
const std::string Thump_Short_Str="Thump";
const std::string Upright_Bass_Short_Str="Uprit";
const std::string Clarinet_Short_Str="Clarnt";
const std::string Breath_Short_Str="Breath";
const std::string Steamer_Short_Str="Steam";
const std::string High_Flute_Short_Str="FluteH";
const std::string Low_Flute_Short_Str="FluteL";
const std::string Guiro_Short_Str="Guiro";
const std::string Indian_Flute_Short_Str="IndFlt";
const std::string Flute_Harmonics_Short_Str="Harmo";
const std::string Lips_1_Short_Str="Lips1";
const std::string Lips_2_Short_Str="Lips2";
const std::string Trumpet_Short_Str="Trumpt";
const std::string Trombones_Short_Str="Bones";
const std::string Contrabass_Short_Str="Contra";
const std::string Cello_Short_Str="Cello";
const std::string Violon_Bow_Short_Str="VioBow";
const std::string Violins_Short_Str="Violns";
const std::string Pizzicart_Short_Str="Pizz";
const std::string Draws_bars_Loop_Short_Str="Drawbr";
const std::string High_Organ_Loop_Short_Str="Horgan";
const std::string Low_Organ_Loop_Short_Str="Lorgan";
const std::string Electric_Piano_Loop_1_Short_Str="EP_lp1";
const std::string Electric_Piano_Loop_2_Short_Str="EP_lp2";
const std::string Clavi_Loop_Short_Str="CLAVlp";
const std::string Harpsichord_Loop_Short_Str="HC_lp";
const std::string Electric_Bass_Loop_1_Short_Str="EB_lp1";
const std::string Acoustic_Bass_Loop_Short_Str="AB_lp";
const std::string Electric_Bass_Loop_2_Short_Str="EB_lp2";
const std::string Electric_Bass_Loop_3_Short_Str="EB_lp3";
const std::string Electric_Guitar_Loop_Short_Str="EG_lp";
const std::string Cello_Loop_Short_Str="CELLlp";
const std::string Violin_Loop_Short_Str="VIOLlp";
const std::string Lead_Loop_Short_Str="Reedlp";
const std::string Sax_Loop_1_Short_Str="SAXlp1";
const std::string Sax_Loop_2_Short_Str="SAXlp2";
const std::string Aah_Loop_Short_Str="Aah_lp";
const std::string Ooh_Loop_Short_Str="Ooh_lp";
const std::string Male_Loop_1_Short_Str="Manlp1";
const std::string Spectrum_1_Loop_Short_Str="Spect1";
const std::string Spectrum_2_Loop_Short_Str="Spect2";
const std::string Spectrum_3_Loop_Short_Str="Spect3";
const std::string Spectrum_4_Loop_Short_Str="Spect4";
const std::string Spectrum_5_Loop_Short_Str="Spect5";
const std::string Spectrum_6_Loop_Short_Str="Spect6";
const std::string Spectrum_7_Loop_Short_Str="Spect7";
const std::string Male_Loop_2_Short_Str="Manlp2";
const std::string Noise_Loop_Short_Str="Noise";
const std::string Loop_01_Short_Str="Loop01";
const std::string Loop_02_Short_Str="Loop02";
const std::string Loop_03_Short_Str="Loop03";
const std::string Loop_04_Short_Str="Loop04";
const std::string Loop_05_Short_Str="Loop05";
const std::string Loop_06_Short_Str="Loop06";
const std::string Loop_07_Short_Str="Loop07";
const std::string Loop_08_Short_Str="Loop08";
const std::string Loop_09_Short_Str="Loop09";
const std::string Loop_10_Short_Str="Loop10";
const std::string Loop_11_Short_Str="Loop11";
const std::string Loop_12_Short_Str="Loop12";
const std::string Loop_13_Short_Str="Loop13";
const std::string Loop_14_Short_Str="Loop14";
const std::string Loop_15_Short_Str="Loop15";
const std::string Loop_16_Short_Str="Loop16";
const std::string Loop_17_Short_Str="Loop17";
const std::string Loop_18_Short_Str="Loop18";
const std::string Loop_19_Short_Str="Loop19";
const std::string Loop_20_Short_Str="Loop20";
const std::string Loop_21_Short_Str="Loop21";
const std::string Loop_22_Short_Str="Loop22";
const std::string Loop_23_Short_Str="Loop23";
const std::string Loop_24_Short_Str="Loop24";


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
    // Constructor destructor
    WG();
    ~WG();

    // Affect methods
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

    // Access methods
    unsigned char getPitchCoarse() const;
    char getPitchFine() const;
    WGLFOMode getLFOMode() const;
    WGPEnvMode getPEnvMode() const;
    WGBenderMode getBenderMode() const;
    WGWaveform getWaveform() const;
    WGPCMWaveNo getPCMWaveNo() const;
    unsigned char getPulseWidth() const;
    char getVelocityRange() const;
    char getAftertouchRange() const;

    // Dump method. Note that 'a' will be incremented accordingly.
    void dump(Address& a, unsigned length, const unsigned char* data);

    // Print and string method
    std::string fracKeyFollowStr() const;
    std::string LFOModeStr(WGLFOMode lm) const;
    std::string LFOModeStr() const;
    std::string PEnvModeStr(WGPEnvMode pem) const;
    std::string PEnvModeStr() const;
    std::string benderModeStr(WGBenderMode bm) const;
    std::string benderModeStr() const;
    std::string waveformStr(WGWaveform wf) const;
    std::string waveformStr() const;
    std::string PCMWaveNoShortStr(WGPCMWaveNo pwn) const;
    std::string PCMWaveNoShortStr() const;
    std::string PCMWaveNoStr(WGPCMWaveNo pwn) const;
    std::string PCMWaveNoStr() const;
    void print(int m) const; // Print the WG with a margine m
};


#endif
