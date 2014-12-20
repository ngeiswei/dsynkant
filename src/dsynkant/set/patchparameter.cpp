/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    patchparameter.cpp

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

#include "patchparameter.hpp"
#include "../commondef/commondef.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constructor destrtuctor
PatchParameter::PatchParameter() {
  setPatchName("DSynkant Init");
  _keyMode = Dual;
  _splitPoint = 24; //corresponds to C4
  _portamentoMode = SUL;
  _holdMode = SUL;
  _UToneKeyShift = 0;
  _LToneKeyShift = 0;
  _UToneFineTune = 0;
  _LToneFineTune = 0;
  _benderRange = 2;
  _aftertouchPitchBend = 0;
  _portamentoTime = 0;
  _outputMode = BTR_MIX;
  _reverbType = SmallHall;
  _reverbBalance = 0;
  _totalVolume = 100;
  _toneBalance = 50;
  _chaseMode = CMULU;
  _chaseLevel = 32;
  _chaseTime = 50;
  _transmitCHBasic = true;
  _transmitCH = 0;
  _separateModeReceiveCHOn = false;
  _separateModeReceiveCH = 0;
  _transmitProgramChangeOn = false;
  _transmitProgramChange = 0;
  _chaseSwitch = false; //unknown ?
  _portamentoSwitch = false; //unknown ?
  _separateSwitch = false; //unknown ?
  _transmitBankSelectOn = false; //unknown ?
  _transmitBankSelect = 0; //unknown ?
  _LowerOn = true; //unknown ?
  _UpperOn = true; //unknown ?
  _LowerPartial1On = true; //unknown ?
  _LowerPartial2On = true; //unknown ?
  _UpperPartial1On = true; //unknown ?
  _UpperPartial2On = true; //unknown ?
}

PatchParameter::~PatchParameter() {
}

//affect methods  
void PatchParameter::setPatchName(char* pn) {
  strncpy(_patchName, pn, PATCHNAME_LENGTH);
  _patchName[PATCHNAME_LENGTH] = '\0';
}
void PatchParameter::setKeyMode(KeyMode km) {
  _keyMode = km;
}
void PatchParameter::setSplitPoint(unsigned char sp) {
  _splitPoint = sp;
}
void PatchParameter::setPortamentoMode(ULSet pm) {
  _portamentoMode = pm;
}
void PatchParameter::setHoldMode(ULSet hm) {
  _holdMode = hm;
}
void PatchParameter::setUToneKeyShift(char u) {
  _UToneKeyShift = u;
}
void PatchParameter::setLToneKeyShift(char l) {
  _LToneKeyShift = l;
}
void PatchParameter::setUToneFineTune(char u) {
  _UToneFineTune = u;
}
void PatchParameter::setLToneFineTune(char l) {
  _LToneFineTune = l;
}
void PatchParameter::setBenderRange(unsigned char br) {
  _benderRange = br;
}
void PatchParameter::setAftertouchPitchBend(char ap) {
  _aftertouchPitchBend = ap;
}
void PatchParameter::setPortamentoTime(unsigned char pt) {
  _portamentoTime = pt;
}
void PatchParameter::setOutputMode(OutputMode om) {
  _outputMode = om;
}
void PatchParameter::setReverbType(ReverbType rt) {
  _reverbType = rt;
}
void PatchParameter::setReverbBalance(unsigned char rb) {
  _reverbBalance = rb;
}
void PatchParameter::setTotalVolume(unsigned char tv) {
  _totalVolume = tv;
}
void PatchParameter::setToneBalance(unsigned char tb) {
  _toneBalance = tb;
}
void PatchParameter::setChaseMode(ChaseMode cm) {
  _chaseMode = cm;
}
void PatchParameter::setChaseLevel(unsigned char cl) {
  _chaseLevel = cl;
}
void PatchParameter::setChaseTime(unsigned char ct) {
  _chaseTime = ct;
}
void PatchParameter::setTransmitCHBasic(bool b) {
  _transmitCHBasic = b;
}
void PatchParameter::setTransmitCH(unsigned char ch) {
  _transmitCH = ch;
}
void PatchParameter::setSeparateModeReceiveCHOn(bool on) {
  _separateModeReceiveCHOn = on;
}
void PatchParameter::setSeparateModeReceiveCH(unsigned char ch) {
  _separateModeReceiveCH = ch;
}
void PatchParameter::setTransmitProgramChangeOn(bool on) {
  _transmitProgramChangeOn = on;
}
void PatchParameter::setTransmitProgramChange(unsigned char pc) {
  _transmitProgramChange = pc;
}
void PatchParameter::setChaseSwitch(bool cs) {
  _chaseSwitch = cs;
}
void PatchParameter::setPortamentoSwitch(bool ps) {
  _portamentoSwitch = ps;
}
void PatchParameter::setSeparateSwitch(bool ss) {
  _separateSwitch = ss;
}
void PatchParameter::setTransmitBankSelectOn(bool on) {
  _transmitBankSelectOn = on;
}
void PatchParameter::setTransmitBankSelect(unsigned char bs) {
  _transmitBankSelect = bs;
}
void PatchParameter::setLowerOn(bool lo) {
  _LowerOn = lo;
}
void PatchParameter::setUpperOn(bool uo) {
  _UpperOn = uo;
}
void PatchParameter::setLowerPartial1On(bool lp1) {
  _LowerPartial1On = lp1;
}
void PatchParameter::setLowerPartial2On(bool lp2) {
  _LowerPartial2On = lp2;
}
void PatchParameter::setUpperPartial1On(bool up1) {
  _UpperPartial1On = up1;
}
void PatchParameter::setUpperPartial2On(bool up2) {
  _UpperPartial2On = up2;
}

//access methods
char* PatchParameter::getPatchName() {
  return _patchName;
}
KeyMode PatchParameter::getKeyMode() {
  return _keyMode;
}
unsigned char PatchParameter::getSplitPoint() {
  return _splitPoint;
}
ULSet PatchParameter::getPortamentoMode() {
  return _portamentoMode;
}
ULSet PatchParameter::getHoldMode() {
  return _holdMode;
}
char PatchParameter::getUToneKeyShift() {
  return _UToneKeyShift;
}
char PatchParameter::getLToneKeyShift() {
  return _LToneKeyShift;
}
char PatchParameter::getUToneFineTune() {
  return _UToneFineTune;
}
char PatchParameter::getLToneFineTune() {
  return _LToneFineTune;
}
unsigned char PatchParameter::getBenderRange() {
  return _benderRange;
}
char PatchParameter::getAftertouchPitchBend() {
  return _aftertouchPitchBend;
}
unsigned char PatchParameter::getPortamentoTime() {
  return _portamentoTime;
}
OutputMode PatchParameter::getOutputMode() {
  return _outputMode;
}
ReverbType PatchParameter::getReverbType() {
  return _reverbType;
}
unsigned char PatchParameter::getReverbBalance() {
  return _reverbBalance;
}
unsigned char PatchParameter::getTotalVolume() {
  return _totalVolume;
}
unsigned char PatchParameter::getToneBalance() {
  return _toneBalance;
}
ChaseMode PatchParameter::getChaseMode() {
  return _chaseMode;
}
unsigned char PatchParameter::getChaseLevel() {
  return _chaseLevel;
}
unsigned char PatchParameter::getChaseTime() {
  return _chaseTime;
}
bool PatchParameter::getTransmitCHBasic() {
  return _transmitCHBasic;
}
unsigned char PatchParameter::getTransmitCH() {
  return _transmitCH;
}
bool PatchParameter::getSeparateModeReceiveCHOn() {
  return _separateModeReceiveCHOn;
}
unsigned char PatchParameter::getSeparateModeReceiveCH() {
  return _separateModeReceiveCH;
}
bool PatchParameter::getTransmitProgramChangeOn() {
  return _transmitProgramChangeOn;
}
unsigned char PatchParameter::getTransmitProgramChange() {
  return _transmitProgramChange;
}
bool PatchParameter::getChaseSwitch() {
  return _chaseSwitch;
}
bool PatchParameter::getPortamentoSwitch() {
  return _portamentoSwitch;
}
bool PatchParameter::getSeparateSwitch() {
  return _separateSwitch;
}
bool PatchParameter::getTransmitBankSelectOn() {
  return _transmitBankSelectOn;
}
unsigned char PatchParameter::getTransmitBankSelect() {
  return _transmitBankSelect;
}
bool PatchParameter::getLowerOn() {
  return _LowerOn;
}
bool PatchParameter::getUpperOn() {
  return _UpperOn;
}
bool PatchParameter::getLowerPartial1On() {
  return _LowerPartial1On;
}
bool PatchParameter::getLowerPartial2On() {
  return _LowerPartial2On;
}
bool PatchParameter::getUpperPartial1On() {
  return _UpperPartial1On;
}
bool PatchParameter::getUpperPartial2On() {
  return _UpperPartial2On;
}

//dump method
void PatchParameter::dump(Address& a, unsigned length, unsigned char* data) {
  Address cura;
  unsigned index = 0;
  if(a == cura) {
    while(index < length && index < PATCHNAME_LENGTH) {
      _patchName[index] = D50CharToASCII(data[index]);
      index++;
      ++a;
    }
    _patchName[index] = 0;
  }
  cura += PATCHNAME_LENGTH;
  if(length > index && a == cura) {
    _keyMode = (KeyMode)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _splitPoint = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _portamentoMode = (ULSet)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _holdMode = (ULSet)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _UToneKeyShift = (char)data[index] - 24;
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _LToneKeyShift = (char)data[index] - 24;
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _UToneFineTune = (char)data[index] - 50;
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _LToneFineTune = (char)data[index] - 50;
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _benderRange = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _aftertouchPitchBend = (char)data[index] - 12;
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _portamentoTime = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _outputMode = (OutputMode)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _reverbType = (ReverbType)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _reverbBalance = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _totalVolume = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _toneBalance = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _chaseMode = (ChaseMode)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _chaseLevel = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _chaseTime = data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    if(data[index] == 0) _transmitCHBasic = true;
    else {
      _transmitCHBasic = false;
      _transmitCH = data[index] - 1;
    }
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    if(data[index] == 0) _separateModeReceiveCHOn = false;
    else {
      _separateModeReceiveCHOn = true;
      _separateModeReceiveCH = data[index] - 1;
    }
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    if(data[index] == 0) _transmitProgramChangeOn = false;
    else {
      _transmitProgramChangeOn = true;
      _transmitProgramChange = data[index] - 1;
    }
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _chaseSwitch = (bool)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _portamentoSwitch = (bool)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    _separateSwitch = (bool)data[index];
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    if(data[index] == 0) _transmitBankSelectOn = false;
    else {
      _transmitBankSelectOn = true;
      _transmitBankSelect = data[index] - 1;
    }
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    //Ignore for unkown reason
    //_LowerOn = (bool)(data[index] & 1);
    //_UpperOn = (bool)(data[index] & 2);
    index++;
    ++a;
  }
  ++cura;
  if(length > index && a == cura) {
    //Ignore for unkown reason
    //_LowerPartial1On = (bool)(data[index] & 1);
    //_LowerPartial2On = (bool)(data[index] & 2);
    //_UpperPartial1On = (bool)(data[index] & 4);
    //_UpperPartial2On = (bool)(data[index] & 8);
    Address last(DUMP_PATCHPARAMETER_LENGTH);
    a = last;
  }
}

//print methods
char* PatchParameter::KeyModeStr(KeyMode km) {
  switch(km) {
  case Whole : return "Whole"; break;
  case Dual : return "Dual"; break;
  case Split : return "Split"; break;
  case Separate : return "Separate"; break;
  case Whole_S : return "Whole_S"; break;
  case Dual_S : return "Dual_S"; break;
  case Split_US : return "Split_US"; break;
  case Split_LS : return "Split_LS"; break;
  case Separate_S : return "Separate_S"; break;
  default :
    printf("PatchParameter::KeyModeStr : impossible case\n");
    return NULL;
    break;
  }
}
char* PatchParameter::KeyModeStr() {
  return KeyModeStr(_keyMode);
}
char* PatchParameter::ULSetStr(ULSet uls) {
  switch(uls) {
  case SU : return SUStr; break;
  case SL : return SLStr; break;
  case SUL : return SULStr; break;
  default :
    printf("PatchParameter::ULSetStr : impossible case\n");
    return NULL;
    break;
  }
}
char* PatchParameter::OutputModeStr(OutputMode om) {
  switch(om) {
  case BTR_MIX : return BTR_MIX_Str; break;
  case BTR_SEP : return BTR_SEP_Str; break;
  case UTR_SEP : return UTR_SEP_Str; break;
  case LTR_SEP : return LTR_SEP_Str; break;
  default :
    printf("PatchParameter::OutputModeStr : impossible case\n");
    return NULL;
    break;
  }
}
char* PatchParameter::OutputModeStr() {
  return OutputModeStr(_outputMode);
}
char* PatchParameter::ReverbTypeStr(ReverbType rt) {
  switch(rt) {
  case SmallHall : return SmallHall_Str; break;
  case MediumHall : return MediumHall_Str; break;
  case LargeHall : return LargeHall_Str; break;
  case Chapel : return Chapel_Str; break;
  case Box : return Box_Str; break;
  case SmallMetalRoom : return SmallMetalRoom_Str; break;
  case SmallRoom : return SmallRoom_Str; break;
  case MediumRoom : return MediumRoom_Str; break;
  case MediumLargeRoom : return MediumLargeRoom_Str; break;
  case LargeRoom : return LargeRoom_Str; break;
  case SimpleDelay_102ms : return SimpleDelay_102ms_Str; break;
  case CrossDelay_180ms : return CrossDelay_180ms_Str; break;
  case CrossDelay_224ms : return CrossDelay_224ms_Str; break;
  case CrossDelay_148_296ms : return CrossDelay_148_296ms_Str; break;
  case ShortGate_200ms : return ShortGate_200ms_Str; break;
  case LongGate_480ms : return LongGate_480ms_Str; break;
  case BrightHall : return BrightHall_Str; break;
  case LargeCave : return LargeCave_Str; break;
  case SteelPan : return SteelPan_Str; break;
  case Delay_248ms : return Delay_248ms_Str; break;
  case Delay_338ms : return Delay_338ms_Str; break;
  case CrossDelay_157ms : return CrossDelay_157ms_Str; break;
  case CrossDelay_252ms : return CrossDelay_252ms_Str; break;
  case CrossDelay_274_137ms : return CrossDelay_274_137ms_Str; break;
  case GateReverb : return GateReverb_Str; break;
  case ReverseGate_360ms : return ReverseGate_360ms_Str; break;
  case ReverseGate_480ms : return ReverseGate_480ms_Str; break;
  case ShortSlapBack : return ShortSlapBack_Str; break;
  case MediumSlapBack : return MediumSlapBack_Str; break;
  case LongSlapBack : return LongSlapBack_Str; break;
  case TwistedSpace : return TwistedSpace_Str; break;
  case Space : return Space_Str; break;
  default :
    printf("PatchParameter::ReverbTypeStr : impossible case\n");
    return NULL;
    break;
  }
}
char* PatchParameter::ReverbTypeStr() {
  return ReverbTypeStr(_reverbType);
}
char* PatchParameter::ChaseModeStr(ChaseMode cm) {
  switch(cm) {
  case CMUL : return CMULStr; break;
  case CMULL : return CMULLStr; break;
  case CMULU : return CMULUStr; break;
  default :
    printf("PatchParameter::ChaseModeStr : impossible case\n");
    return NULL;
    break;
  }
}
char* PatchParameter::ChaseModeStr() {
  return ChaseModeStr(_chaseMode);
}
char* PatchParameter::pitchStr(int p) {
  int octave = p/12 + 2;
  char* sOct = (char *) malloc(sizeof(char)*128);
  sprintf(sOct, "%d", octave);
  int note = p%12;
  char* sNote = (char *) malloc(sizeof(char)*128);
  switch(note) {
  case 0: strcpy(sNote,"C");
    break;
  case 1: strcpy(sNote, "C#");
    break;
  case 2: strcpy(sNote, "D");
    break;
  case 3: strcpy(sNote, "D#");
    break;
  case 4: strcpy(sNote, "E");
    break;
  case 5: strcpy(sNote, "F");
    break;
  case 6: strcpy(sNote, "F#");
    break;
  case 7: strcpy(sNote, "G");
    break;
  case 8: strcpy(sNote, "G#");
    break;
  case 9: strcpy(sNote, "A");
    break;
  case 10: strcpy(sNote, "A#");
    break;
  case 11: strcpy(sNote, "B");
    break;
  default:
    printf("PatchParameter::pitchStr Error : impossible case\n");
    strcpy(sNote, "");
    break;
  }
  return strcat(sNote, sOct);
}
void PatchParameter::print(int m) {
  ps(m);
  printf("Patch name = %s\n", getPatchName());
  ps(m);
  printf("Key mode = %s\n", KeyModeStr());
  ps(m);
  printf("Split point = %s\n", pitchStr(_splitPoint));
  ps(m);
  printf("Portamento mode = %s\n", ULSetStr(_portamentoMode));
  ps(m);
  printf("Hold mode = %s\n", ULSetStr(_holdMode));
  ps(m);
  printf("UTone key shift = %d\n", _UToneKeyShift);
  ps(m);
  printf("LTone key shift = %d\n", _LToneKeyShift);
  ps(m);
  printf("UTone fine tune = %d\n", _UToneFineTune);
  ps(m);
  printf("LTone fine tune = %d\n", _LToneFineTune);
  ps(m);
  printf("Bender range = %d\n", _benderRange);
  ps(m);
  printf("Aftertouch pitch bend = %d\n", _aftertouchPitchBend);
  ps(m);
  printf("Portamento time = %d\n", _portamentoTime);
  ps(m);
  printf("Output mode = %s\n", OutputModeStr());
  ps(m);
  printf("Reverb type = %s\n", ReverbTypeStr());
  ps(m);
  printf("Reverb balance = %d\n", _reverbBalance);
  ps(m);
  printf("Total volume = %d\n", _totalVolume);
  ps(m);
  printf("Tone balance = %d\n", _toneBalance);
  ps(m);
  printf("Chase mode = %s\n", ChaseModeStr());
  ps(m);
  printf("Chase level = %d\n", _chaseLevel);
  ps(m);
  printf("Chase time = %d\n", _chaseTime);
  ps(m);
  printf("MIDI Transmit CH = ");
  if(_transmitCHBasic) printf("Basic\n");
  else printf("%d\n", _transmitCH);
  ps(m);
  printf("MIDI Separate mode receive CH = ");
  if(_separateModeReceiveCHOn) printf("%d\n", _separateModeReceiveCH);
  else printf("Off\n");
  ps(m);
  printf("MIDI Transmit program change = ");
  if(_transmitProgramChangeOn) printf("%d\n", _transmitProgramChange);
  else printf("Off\n");
  ps(m);
  printf("Chase switch = %d\n", (int) _chaseSwitch);
  ps(m);
  printf("Portamento switch = %d\n", (int) _portamentoSwitch);
  ps(m);
  printf("Separate switch = %d\n", (int) _separateSwitch);
  ps(m);
  printf("MIDI Transmit bank select = ");
  if(_transmitBankSelectOn) printf("%d\n", _transmitBankSelect);
  else printf("Off\n");
  ps(m);
  printf("LowerOn = %d\n", (int) _LowerOn);
  ps(m);
  printf("UpperOn = %d\n", (int) _UpperOn);
  ps(m);
  printf("LowerPartial1On = %d\n", (int) _LowerPartial1On);
  ps(m);
  printf("LowerPartial2On = %d\n", (int) _LowerPartial2On);
  ps(m);
  printf("UpperPartial1On = %d\n", (int) _UpperPartial1On);
  ps(m);
  printf("UpperPartial1On = %d\n", (int) _UpperPartial2On);
}
