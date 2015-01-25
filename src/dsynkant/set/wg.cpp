/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    wg.cpp

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

#include <iostream>

#include "wg.hpp"

using namespace dsynkant;

//Constructor destructor
WG::WG() {
	_pitchCoarse = 24;
	_pitchFine = 0;
	_keyFollow = FracKeyFollow::plus1;
	_LFOMode = LMAnL;
	_PEnvMode = PEMplus;
	_benderMode = BMkeyFollow;
	_waveform = sawtooth;
	_PCMWaveNo = WGPCMWaveNo::Marimba;
	_pulseWidth = 0;
	_velocityRange = 0;
	_aftertouchRange = 0;
}

WG::~WG() {
}

//affect methods
void WG::setPitchCoarse(unsigned char pc) {
	_pitchCoarse = pc;
}
void WG::setPitchFine(char pf) {
	_pitchFine = pf;
}
void WG::setLFOMode(WGLFOMode lm) {
	_LFOMode = lm;
}
void WG::setPEnvMode(WGPEnvMode pm) {
	_PEnvMode = pm;
}
void WG::setBenderMode(WGBenderMode bm) {
	_benderMode = bm;
}
void WG::setWaveform(WGWaveform wf) {
	_waveform = wf;
}
void WG::setPCMWaveNo(WGPCMWaveNo pwm) {
	_PCMWaveNo = pwm;
}
void WG::setPulseWidth(unsigned char pw) {
	_pulseWidth = pw;
}
void WG::setVelocityRange(char vr) {
	_velocityRange = vr;
}
void WG::setAftertouchRange(char ar) {
	_aftertouchRange = ar;
}

//access methods
unsigned char WG::getPitchCoarse() const {
	return _pitchCoarse;
}
char WG::getPitchFine() const {
	return _pitchFine;
}
WGLFOMode WG::getLFOMode() const {
	return _LFOMode;
}
WGPEnvMode WG::getPEnvMode() const {
	return _PEnvMode;
}
WGBenderMode WG::getBenderMode() const {
	return _benderMode;
}
WGWaveform WG::getWaveform() const {
	return _waveform;
}
WGPCMWaveNo WG::getPCMWaveNo() const {
	return _PCMWaveNo;
}
unsigned char WG::getPulseWidth() const {
	return _pulseWidth;
}
char WG::getVelocityRange() const {
	return _velocityRange;
}
char WG::getAftertouchRange() const {
	return _aftertouchRange;
}

void WG::dump(Address& a, unsigned length, const unsigned char* data) {
	Address lowBound;
	Address upBound(1);
	unsigned index = 0;
	if(length > index && a == lowBound) {
		_pitchCoarse = data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_pitchFine = (char)data[index] - 50;
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_keyFollow = (FracKeyFollow)data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_LFOMode = (WGLFOMode)data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_PEnvMode = (WGPEnvMode)data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_benderMode = (WGBenderMode)data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_waveform = (WGWaveform)data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_PCMWaveNo = (WGPCMWaveNo)data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_pulseWidth = data[index];
		index++;
		++a;
	}
	++lowBound;
	++upBound;
	if(length > index && a == lowBound) {
		_velocityRange = (char)data[index] - 7;
		index++;
		++a;
	}
	++lowBound;
	upBound += DUMP_MODULATION_LENGTH;
	if(length > index && a >= lowBound && a < upBound) {
		Address la = a - lowBound;
		Address prela = la;
		BaseModulation::dump(la, length - index, &data[index]);
		Address diffa = la - prela;
		index += diffa.toInt();
		a += diffa;
	}
	lowBound += DUMP_MODULATION_LENGTH;
	++upBound;
	if(length > index ) {
		_aftertouchRange = (char)data[index] - 7;
		++a;
	}
}

std::string WG::fracKeyFollowStr() const {
	return FracKeyFollowStr(_keyFollow);
}
std::string WG::LFOModeStr(WGLFOMode lm) const {
	switch(lm) {
	case LMoff : return offStr; break;
	case LMplus : return plusStr; break;
	case LMminus : return minusStr; break;
	case LMAnL : return AnLStr; break;
	default :
		printf("WG::LFOModeStr : impossible case\n");
		return NULL;
		break;
	}
}
std::string WG::LFOModeStr() const {
	return LFOModeStr(_LFOMode);
}
std::string WG::PEnvModeStr(WGPEnvMode pem) const {
	switch(pem) {
	case PEMoff : return offStr; break;
	case PEMplus : return plusStr; break;
	case PEMminus : return minusStr; break;
	default :
		printf("WG::PENVModeStr : impossible case\n");
		return NULL;
		break;
	}
}
std::string WG::PEnvModeStr() const {
	return PEnvModeStr(_PEnvMode);
}
std::string WG::benderModeStr(WGBenderMode bm) const {
	switch(bm) {
	case BMoff : return offStr; break;
	case BMkeyFollow : return keyFollowStr; break;
	case BMnormal : return normalStr; break;
	default :
		printf("WG::BenderModeStr : impossible case\n");
		return NULL;
		break;
	}
}
std::string WG::benderModeStr() const {
	return benderModeStr(_benderMode);
}
std::string WG::waveformStr(WGWaveform wf) const {
	switch(wf) {
	case square : return squareStr; break;
	case sawtooth : return sawtoothStr; break;
	default :
		printf("WG::waveformStr : impossible case\n");
		return NULL;
		break;
	}
}
std::string WG::waveformStr() const {
	return waveformStr(_waveform);
}
std::string WG::PCMWaveNoStr(WGPCMWaveNo pwn) const {
	switch(pwn) {
	case WGPCMWaveNo::Marimba : return Marimba_Str; break;
	case WGPCMWaveNo::Vibraphone : return Vibraphone_Str; break;
	case WGPCMWaveNo::Xylophone_1 : return Xylophone_1_Str; break;
	case WGPCMWaveNo::Xylophone_2 : return Xylophone_2_Str; break;
	case WGPCMWaveNo::Log_Bass : return Log_Bass_Str; break;
	case WGPCMWaveNo::Hammer : return Hammer_Str; break;
	case WGPCMWaveNo::Japanese_Drum : return Japanese_Drum_Str; break;
	case WGPCMWaveNo::Kalimba : return Kalimba_Str; break;
	case WGPCMWaveNo::Pluck_1 : return Pluck_1_Str; break;
	case WGPCMWaveNo::Chink : return Chink_Str; break;
	case WGPCMWaveNo::Agogo : return Agogo_Str; break;
	case WGPCMWaveNo::Triangle : return Triangle_Str; break;
	case WGPCMWaveNo::Bells : return Bells_Str; break;
	case WGPCMWaveNo::NailFile : return Nail_File_Str; break;
	case WGPCMWaveNo::Pick : return Pick_Str; break;
	case WGPCMWaveNo::Low_Piano : return Low_Piano_Str; break;
	case WGPCMWaveNo::Mid_Piano : return Mid_Piano_Str; break;
	case WGPCMWaveNo::High_Piano : return High_Piano_Str; break;
	case WGPCMWaveNo::Harpsichord : return Harpsichord_Str; break;
	case WGPCMWaveNo::Harp : return Harp_Str; break;
	case WGPCMWaveNo::Organ_Percussion : return Organ_Percussion_Str; break;
	case WGPCMWaveNo::Steel_Strings : return Steel_Strings_Str; break;
	case WGPCMWaveNo::Nylon_Strings : return Nylon_Strings_Str; break;
	case WGPCMWaveNo::Electric_Guitar_1 : return Electric_Guitar_1_Str; break;
	case WGPCMWaveNo::Electric_Guitar_2 : return Electric_Guitar_2_Str; break;
	case WGPCMWaveNo::Dirty_Guitar : return Dirty_Guitar_Str; break;
	case WGPCMWaveNo::Pick_Bass : return Pick_Bass_Str; break;
	case WGPCMWaveNo::Pop_Bass : return Pop_Bass_Str; break;
	case WGPCMWaveNo::Thump : return Thump_Str; break;
	case WGPCMWaveNo::Upright_Bass : return Upright_Bass_Str; break;
	case WGPCMWaveNo::Clarinet : return Clarinet_Str; break;
	case WGPCMWaveNo::Breath : return Breath_Str; break;
	case WGPCMWaveNo::Steamer : return Steamer_Str; break;
	case WGPCMWaveNo::High_Flute : return High_Flute_Str; break;
	case WGPCMWaveNo::Low_Flute : return Low_Flute_Str; break;
	case WGPCMWaveNo::Guiro : return Guiro_Str; break;
	case WGPCMWaveNo::Indian_Flute : return Indian_Flute_Str; break;
	case WGPCMWaveNo::Flute_Harmonics : return Flute_Harmonics_Str; break;
	case WGPCMWaveNo::Lips_1 : return Lips_1_Str; break;
	case WGPCMWaveNo::Lips_2 : return Lips_2_Str; break;
	case WGPCMWaveNo::Trumpet : return Trumpet_Str; break;
	case WGPCMWaveNo::Trombones : return Trombones_Str; break;
	case WGPCMWaveNo::Contrabass : return Contrabass_Str; break;
	case WGPCMWaveNo::Cello : return Cello_Str; break;
	case WGPCMWaveNo::Violon_Bow : return Violon_Bow_Str; break;
	case WGPCMWaveNo::Violins : return Violins_Str; break;
	case WGPCMWaveNo::Pizzicart : return Pizzicart_Str; break;
	case WGPCMWaveNo::Draws_bars_Loop : return Draws_bars_Loop_Str; break;
	case WGPCMWaveNo::High_Organ_Loop : return High_Organ_Loop_Str; break;
	case WGPCMWaveNo::Low_Organ_Loop : return Low_Organ_Loop_Str; break;
	case WGPCMWaveNo::Electric_Piano_Loop_1 : return Electric_Piano_Loop_1_Str; break;
	case WGPCMWaveNo::Electric_Piano_Loop_2 : return Electric_Piano_Loop_2_Str; break;
	case WGPCMWaveNo::Clavi_Loop : return Clavi_Loop_Str; break;
	case WGPCMWaveNo::Harpsichord_Loop : return Harpsichord_Loop_Str; break;
	case WGPCMWaveNo::Electric_Bass_Loop_1 : return Electric_Bass_Loop_1_Str; break;
	case WGPCMWaveNo::Acoustic_Bass_Loop : return Acoustic_Bass_Loop_Str; break;
	case WGPCMWaveNo::Electric_Bass_Loop_2 : return Electric_Bass_Loop_2_Str; break;
	case WGPCMWaveNo::Electric_Bass_Loop_3 : return Electric_Bass_Loop_3_Str; break;
	case WGPCMWaveNo::Electric_Guitar_Loop : return Electric_Guitar_Loop_Str; break;
	case WGPCMWaveNo::Cello_Loop : return Cello_Loop_Str; break;
	case WGPCMWaveNo::Violin_Loop : return Violin_Loop_Str; break;
	case WGPCMWaveNo::Lead_Loop : return Lead_Loop_Str; break;
	case WGPCMWaveNo::Sax_Loop_1 : return Sax_Loop_1_Str; break;
	case WGPCMWaveNo::Sax_Loop_2 : return Sax_Loop_2_Str; break;
	case WGPCMWaveNo::Aah_Loop : return Aah_Loop_Str; break;
	case WGPCMWaveNo::Ooh_Loop : return Ooh_Loop_Str; break;
	case WGPCMWaveNo::Male_Loop_1 : return Male_Loop_1_Str; break;
	case WGPCMWaveNo::Spectrum_1_Loop : return Spectrum_1_Loop_Str; break;
	case WGPCMWaveNo::Spectrum_2_Loop : return Spectrum_2_Loop_Str; break;
	case WGPCMWaveNo::Spectrum_3_Loop : return Spectrum_3_Loop_Str; break;
	case WGPCMWaveNo::Spectrum_4_Loop : return Spectrum_4_Loop_Str; break;
	case WGPCMWaveNo::Spectrum_5_Loop : return Spectrum_5_Loop_Str; break;
	case WGPCMWaveNo::Spectrum_6_Loop : return Spectrum_6_Loop_Str; break;
	case WGPCMWaveNo::Spectrum_7_Loop : return Spectrum_7_Loop_Str; break;
	case WGPCMWaveNo::Male_Loop_2 : return Male_Loop_2_Str; break;
	case WGPCMWaveNo::Noise_Loop : return Noise_Loop_Str; break;
	case WGPCMWaveNo::Loop_01 : return Loop_01_Str; break;
	case WGPCMWaveNo::Loop_02 : return Loop_02_Str; break;
	case WGPCMWaveNo::Loop_03 : return Loop_03_Str; break;
	case WGPCMWaveNo::Loop_04 : return Loop_04_Str; break;
	case WGPCMWaveNo::Loop_05 : return Loop_05_Str; break;
	case WGPCMWaveNo::Loop_06 : return Loop_06_Str; break;
	case WGPCMWaveNo::Loop_07 : return Loop_07_Str; break;
	case WGPCMWaveNo::Loop_08 : return Loop_08_Str; break;
	case WGPCMWaveNo::Loop_09 : return Loop_09_Str; break;
	case WGPCMWaveNo::Loop_10 : return Loop_10_Str; break;
	case WGPCMWaveNo::Loop_11 : return Loop_11_Str; break;
	case WGPCMWaveNo::Loop_12 : return Loop_12_Str; break;
	case WGPCMWaveNo::Loop_13 : return Loop_13_Str; break;
	case WGPCMWaveNo::Loop_14 : return Loop_14_Str; break;
	case WGPCMWaveNo::Loop_15 : return Loop_15_Str; break;
	case WGPCMWaveNo::Loop_16 : return Loop_16_Str; break;
	case WGPCMWaveNo::Loop_17 : return Loop_17_Str; break;
	case WGPCMWaveNo::Loop_18 : return Loop_18_Str; break;
	case WGPCMWaveNo::Loop_19 : return Loop_19_Str; break;
	case WGPCMWaveNo::Loop_20 : return Loop_20_Str; break;
	case WGPCMWaveNo::Loop_21 : return Loop_21_Str; break;
	case WGPCMWaveNo::Loop_22 : return Loop_22_Str; break;
	case WGPCMWaveNo::Loop_23 : return Loop_23_Str; break;
	case WGPCMWaveNo::Loop_24 : return Loop_24_Str; break;
	default :
		std::cerr << "WG::PCMWaveNoStr : impossible case";
		return std::string();
	}
}
std::string WG::PCMWaveNoStr() const {
	return PCMWaveNoStr(_PCMWaveNo);
}
std::string WG::PCMWaveNoShortStr(WGPCMWaveNo pwn) const {
	switch(pwn) {
	case WGPCMWaveNo::Marimba : return Marimba_Short_Str; break;
	case WGPCMWaveNo::Vibraphone : return Vibraphone_Short_Str; break;
	case WGPCMWaveNo::Xylophone_1 : return Xylophone_1_Short_Str; break;
	case WGPCMWaveNo::Xylophone_2 : return Xylophone_2_Short_Str; break;
	case WGPCMWaveNo::Log_Bass : return Log_Bass_Short_Str; break;
	case WGPCMWaveNo::Hammer : return Hammer_Short_Str; break;
	case WGPCMWaveNo::Japanese_Drum : return Japanese_Drum_Short_Str; break;
	case WGPCMWaveNo::Kalimba : return Kalimba_Short_Str; break;
	case WGPCMWaveNo::Pluck_1 : return Pluck_1_Short_Str; break;
	case WGPCMWaveNo::Chink : return Chink_Short_Str; break;
	case WGPCMWaveNo::Agogo : return Agogo_Short_Str; break;
	case WGPCMWaveNo::Triangle : return Triangle_Short_Str; break;
	case WGPCMWaveNo::Bells : return Bells_Short_Str; break;
	case WGPCMWaveNo::NailFile : return Nail_File_Short_Str; break;
	case WGPCMWaveNo::Pick : return Pick_Short_Str; break;
	case WGPCMWaveNo::Low_Piano : return Low_Piano_Short_Str; break;
	case WGPCMWaveNo::Mid_Piano : return Mid_Piano_Short_Str; break;
	case WGPCMWaveNo::High_Piano : return High_Piano_Short_Str; break;
	case WGPCMWaveNo::Harpsichord : return Harpsichord_Short_Str; break;
	case WGPCMWaveNo::Harp : return Harp_Short_Str; break;
	case WGPCMWaveNo::Organ_Percussion : return Organ_Percussion_Short_Str; break;
	case WGPCMWaveNo::Steel_Strings : return Steel_Strings_Short_Str; break;
	case WGPCMWaveNo::Nylon_Strings : return Nylon_Strings_Short_Str; break;
	case WGPCMWaveNo::Electric_Guitar_1 : return Electric_Guitar_1_Short_Str; break;
	case WGPCMWaveNo::Electric_Guitar_2 : return Electric_Guitar_2_Short_Str; break;
	case WGPCMWaveNo::Dirty_Guitar : return Dirty_Guitar_Short_Str; break;
	case WGPCMWaveNo::Pick_Bass : return Pick_Bass_Short_Str; break;
	case WGPCMWaveNo::Pop_Bass : return Pop_Bass_Short_Str; break;
	case WGPCMWaveNo::Thump : return Thump_Short_Str; break;
	case WGPCMWaveNo::Upright_Bass : return Upright_Bass_Short_Str; break;
	case WGPCMWaveNo::Clarinet : return Clarinet_Short_Str; break;
	case WGPCMWaveNo::Breath : return Breath_Short_Str; break;
	case WGPCMWaveNo::Steamer : return Steamer_Short_Str; break;
	case WGPCMWaveNo::High_Flute : return High_Flute_Short_Str; break;
	case WGPCMWaveNo::Low_Flute : return Low_Flute_Short_Str; break;
	case WGPCMWaveNo::Guiro : return Guiro_Short_Str; break;
	case WGPCMWaveNo::Indian_Flute : return Indian_Flute_Short_Str; break;
	case WGPCMWaveNo::Flute_Harmonics : return Flute_Harmonics_Short_Str; break;
	case WGPCMWaveNo::Lips_1 : return Lips_1_Short_Str; break;
	case WGPCMWaveNo::Lips_2 : return Lips_2_Short_Str; break;
	case WGPCMWaveNo::Trumpet : return Trumpet_Short_Str; break;
	case WGPCMWaveNo::Trombones : return Trombones_Short_Str; break;
	case WGPCMWaveNo::Contrabass : return Contrabass_Short_Str; break;
	case WGPCMWaveNo::Cello : return Cello_Short_Str; break;
	case WGPCMWaveNo::Violon_Bow : return Violon_Bow_Short_Str; break;
	case WGPCMWaveNo::Violins : return Violins_Short_Str; break;
	case WGPCMWaveNo::Pizzicart : return Pizzicart_Short_Str; break;
	case WGPCMWaveNo::Draws_bars_Loop : return Draws_bars_Loop_Short_Str; break;
	case WGPCMWaveNo::High_Organ_Loop : return High_Organ_Loop_Short_Str; break;
	case WGPCMWaveNo::Low_Organ_Loop : return Low_Organ_Loop_Short_Str; break;
	case WGPCMWaveNo::Electric_Piano_Loop_1 : return Electric_Piano_Loop_1_Short_Str; break;
	case WGPCMWaveNo::Electric_Piano_Loop_2 : return Electric_Piano_Loop_2_Short_Str; break;
	case WGPCMWaveNo::Clavi_Loop : return Clavi_Loop_Short_Str; break;
	case WGPCMWaveNo::Harpsichord_Loop : return Harpsichord_Loop_Short_Str; break;
	case WGPCMWaveNo::Electric_Bass_Loop_1 : return Electric_Bass_Loop_1_Short_Str; break;
	case WGPCMWaveNo::Acoustic_Bass_Loop : return Acoustic_Bass_Loop_Short_Str; break;
	case WGPCMWaveNo::Electric_Bass_Loop_2 : return Electric_Bass_Loop_2_Short_Str; break;
	case WGPCMWaveNo::Electric_Bass_Loop_3 : return Electric_Bass_Loop_3_Short_Str; break;
	case WGPCMWaveNo::Electric_Guitar_Loop : return Electric_Guitar_Loop_Short_Str; break;
	case WGPCMWaveNo::Cello_Loop : return Cello_Loop_Short_Str; break;
	case WGPCMWaveNo::Violin_Loop : return Violin_Loop_Short_Str; break;
	case WGPCMWaveNo::Lead_Loop : return Lead_Loop_Short_Str; break;
	case WGPCMWaveNo::Sax_Loop_1 : return Sax_Loop_1_Short_Str; break;
	case WGPCMWaveNo::Sax_Loop_2 : return Sax_Loop_2_Short_Str; break;
	case WGPCMWaveNo::Aah_Loop : return Aah_Loop_Short_Str; break;
	case WGPCMWaveNo::Ooh_Loop : return Ooh_Loop_Short_Str; break;
	case WGPCMWaveNo::Male_Loop_1 : return Male_Loop_1_Short_Str; break;
	case WGPCMWaveNo::Spectrum_1_Loop : return Spectrum_1_Loop_Short_Str; break;
	case WGPCMWaveNo::Spectrum_2_Loop : return Spectrum_2_Loop_Short_Str; break;
	case WGPCMWaveNo::Spectrum_3_Loop : return Spectrum_3_Loop_Short_Str; break;
	case WGPCMWaveNo::Spectrum_4_Loop : return Spectrum_4_Loop_Short_Str; break;
	case WGPCMWaveNo::Spectrum_5_Loop : return Spectrum_5_Loop_Short_Str; break;
	case WGPCMWaveNo::Spectrum_6_Loop : return Spectrum_6_Loop_Short_Str; break;
	case WGPCMWaveNo::Spectrum_7_Loop : return Spectrum_7_Loop_Short_Str; break;
	case WGPCMWaveNo::Male_Loop_2 : return Male_Loop_2_Short_Str; break;
	case WGPCMWaveNo::Noise_Loop : return Noise_Loop_Short_Str; break;
	case WGPCMWaveNo::Loop_01 : return Loop_01_Short_Str; break;
	case WGPCMWaveNo::Loop_02 : return Loop_02_Short_Str; break;
	case WGPCMWaveNo::Loop_03 : return Loop_03_Short_Str; break;
	case WGPCMWaveNo::Loop_04 : return Loop_04_Short_Str; break;
	case WGPCMWaveNo::Loop_05 : return Loop_05_Short_Str; break;
	case WGPCMWaveNo::Loop_06 : return Loop_06_Short_Str; break;
	case WGPCMWaveNo::Loop_07 : return Loop_07_Short_Str; break;
	case WGPCMWaveNo::Loop_08 : return Loop_08_Short_Str; break;
	case WGPCMWaveNo::Loop_09 : return Loop_09_Short_Str; break;
	case WGPCMWaveNo::Loop_10 : return Loop_10_Short_Str; break;
	case WGPCMWaveNo::Loop_11 : return Loop_11_Short_Str; break;
	case WGPCMWaveNo::Loop_12 : return Loop_12_Short_Str; break;
	case WGPCMWaveNo::Loop_13 : return Loop_13_Short_Str; break;
	case WGPCMWaveNo::Loop_14 : return Loop_14_Short_Str; break;
	case WGPCMWaveNo::Loop_15 : return Loop_15_Short_Str; break;
	case WGPCMWaveNo::Loop_16 : return Loop_16_Short_Str; break;
	case WGPCMWaveNo::Loop_17 : return Loop_17_Short_Str; break;
	case WGPCMWaveNo::Loop_18 : return Loop_18_Short_Str; break;
	case WGPCMWaveNo::Loop_19 : return Loop_19_Short_Str; break;
	case WGPCMWaveNo::Loop_20 : return Loop_20_Short_Str; break;
	case WGPCMWaveNo::Loop_21 : return Loop_21_Short_Str; break;
	case WGPCMWaveNo::Loop_22 : return Loop_22_Short_Str; break;
	case WGPCMWaveNo::Loop_23 : return Loop_23_Short_Str; break;
	case WGPCMWaveNo::Loop_24 : return Loop_24_Short_Str; break;
	default :
		std::cerr << "WG::PCMWaveNoShortStr : impossible case";
		return std::string();
	}
}
std::string WG::PCMWaveNoShortStr() const {
	return PCMWaveNoShortStr(_PCMWaveNo);
}
void WG::print(int m) const {
	ps(m);
	printf("Pitch (coarse : %d, fine : %d)\n", _pitchCoarse, _pitchFine);
	ps(m);
	printf("Key follow = %s\n", fracKeyFollowStr().c_str());
	ps(m);
	printf("LFO mode = %s\n", LFOModeStr().c_str());
	ps(m);
	printf("PEnv mode = %s\n", PEnvModeStr().c_str());
	ps(m);
	printf("Bender mode = %s\n", benderModeStr().c_str());
	ps(m);
	printf("Waveform mode = %s\n", waveformStr().c_str());
	ps(m);
	printf("PCM wave = %s\n", PCMWaveNoStr().c_str());
	ps(m);
	printf("Pulse width = %d\n", _pulseWidth);
	ps(m);
	printf("Velocity range = %d\n", _velocityRange);
	BaseModulation::print(m);
	ps(m);
	printf("Aftertouch range = %d\n", _aftertouchRange);
}
