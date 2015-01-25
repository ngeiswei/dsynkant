/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    patchparameter.hpp

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

#ifndef __PATCHPARAMETER_HPP
#define __PATCHPARAMETER_HPP

#include <string>

#include "address.hpp"

#define DUMP_PATCHPARAMETER_LENGTH 0x40

#define PATCHNAME_LENGTH 18

const std::string Whole_Str="Whole";
const std::string Dual_Str="Dual";
const std::string Split_Str="Split";
const std::string Separate_Str="Separate";
const std::string Whole_S_Str="Whole_S";
const std::string Dual_S_Str="Dual_S";
const std::string Split_US_Str="Dual_US";
const std::string Split_LS_Str="Split_LS";
const std::string Separate_S_Str="Separate_S";

typedef enum {
	Whole,
	Dual,
	Split,
	Separate,
	Whole_S,
	Dual_S,
	Split_US,
	Split_LS,
	Separate_S
} KeyMode;

#define SUStr "U"
#define SLStr "L"
#define SULStr "UL"

typedef enum {
	SU,
	SL,
	SUL
} ULSet;

const std::string CMULStr="UL";
const std::string CMULLStr="ULL";
const std::string CMULUStr="ULU";

typedef enum {
	CMUL,
	CMULL,
	CMULU
} ChaseMode;

const std::string BTR_MIX_Short_Str="BTR_MIX";
const std::string BTR_SEP_Short_Str="BTR_SEP";
const std::string UTR_SEP_Short_Str="UTR_SEP";
const std::string LTR_SEP_Short_Str="LTR_SEP";

const std::string BTR_MIX_Str="Both tones reverb, mixed signals";
const std::string BTR_SEP_Str="Both tones reverb, seperate signals";
const std::string UTR_SEP_Str="Upper tone reverb, seperate signals";
const std::string LTR_SEP_Str="Lower tone reverb, seperate signals";

typedef enum {
	BTR_MIX, //Both tones reverb, mixed signals
	BTR_SEP, //Both tones reverb, seperate signals
	UTR_SEP, //Upper tone reverb, seperate signals
	LTR_SEP //Lower tone reverb, seperate signals
} OutputMode;

const std::string SmallHall_Str="Small Hall";
const std::string MediumHall_Str="Medium Hall";
const std::string LargeHall_Str="Large Hall";
const std::string Chapel_Str="Chapel";
const std::string Box_Str="Box";
const std::string SmallMetalRoom_Str="Small Metal Room";
const std::string SmallRoom_Str="Small Room";
const std::string MediumRoom_Str="Medium Room";
const std::string MediumLargeRoom_Str="Medium Large Room";
const std::string LargeRoom_Str="Large Room";
const std::string SimpleDelay_102ms_Str="Simple Delay(102ms)";
const std::string CrossDelay_180ms_Str="Cross Delay(180ms)";
const std::string CrossDelay_224ms_Str="Cross Delay(224ms)";
const std::string CrossDelay_148_296ms_Str="Cross Delay(148-296ms)";
const std::string ShortGate_200ms_Str="Short Gate(200ms)";
const std::string LongGate_480ms_Str="Long Gate(480ms)";
const std::string BrightHall_Str="Bright Hall";
const std::string LargeCave_Str="Large Cave";
const std::string SteelPan_Str="Steel Pan";
const std::string Delay_248ms_Str="Delay(248ms)";
const std::string Delay_338ms_Str="Delay(338ms)";
const std::string CrossDelay_157ms_Str="Cross Delay(157ms)";
const std::string CrossDelay_252ms_Str="Cross Delay(252ms)";
const std::string CrossDelay_274_137ms_Str="Cross Delay(274-137ms)";
const std::string GateReverb_Str="Gate Reverb";
const std::string ReverseGate_360ms_Str="Reverse Gate(360ms)";
const std::string ReverseGate_480ms_Str="Reverse Gate(480ms)";
const std::string ShortSlapBack_Str="Short Slap Back";
const std::string MediumSlapBack_Str="Medium Slap Back";
const std::string LongSlapBack_Str="Long Slap Back";
const std::string TwistedSpace_Str="Twisted Space";
const std::string Space_Str="Space";

typedef enum {
	SmallHall,
	MediumHall,
	LargeHall,
	Chapel,
	Box,
	SmallMetalRoom,
	SmallRoom,
	MediumRoom,
	MediumLargeRoom,
	LargeRoom,
	SimpleDelay_102ms,
	CrossDelay_180ms,
	CrossDelay_224ms,
	CrossDelay_148_296ms,
	ShortGate_200ms,
	LongGate_480ms,
	BrightHall,
	LargeCave,
	SteelPan,
	Delay_248ms,
	Delay_338ms,
	CrossDelay_157ms,
	CrossDelay_252ms,
	CrossDelay_274_137ms,
	GateReverb,
	ReverseGate_360ms,
	ReverseGate_480ms,
	ShortSlapBack,
	MediumSlapBack,
	LongSlapBack,
	TwistedSpace,
	Space
} ReverbType;

class PatchParameter {
private:
	std::string _patchName;
	KeyMode _keyMode;
	unsigned char _splitPoint; //between 0 and 60, respectively C2 to C7
	ULSet _portamentoMode;
	ULSet _holdMode;
	char _UToneKeyShift; //between -24 and +24
	char _LToneKeyShift; //between -24 and +24
	char _UToneFineTune; //between -50 and +50
	char _LToneFineTune; //between -50 and +50
	unsigned char _benderRange; //between 0 and 12
	char _aftertouchPitchBend; //between -12 and +12
	unsigned char _portamentoTime; //between 0 and 100
	OutputMode _outputMode;
	ReverbType _reverbType;
	unsigned char _reverbBalance; //between 0 and 100
	unsigned char _totalVolume; //between 0 and 100
	unsigned char _toneBalance; //between 0 and 100
	ChaseMode _chaseMode;
	unsigned char _chaseLevel; //between 0 and 100
	unsigned char _chaseTime; //between 0 and 100
	bool _transmitCHBasic;
	unsigned char _transmitCH; // between 0 and 15
	bool _separateModeReceiveCHOn;
	unsigned char _separateModeReceiveCH; //between 0 and 15
	bool _transmitProgramChangeOn;
	unsigned char _transmitProgramChange; //between 0 and 99
	bool _chaseSwitch;
	bool _portamentoSwitch;
	bool _separateSwitch;
	bool _transmitBankSelectOn;
	unsigned char _transmitBankSelect; //between 0 and 99
	bool _LowerOn;
	bool _UpperOn;
	bool _LowerPartial1On;
	bool _LowerPartial2On;
	bool _UpperPartial1On;
	bool _UpperPartial2On;

public:
	PatchParameter();
	~PatchParameter();

	// Affect methods
	void setPatchName(const std::string& pn);
	void setKeyMode(KeyMode km);
	void setSplitPoint(unsigned char sp);
	void setPortamentoMode(ULSet pm);
	void setHoldMode(ULSet hm);
	void setUToneKeyShift(char u);
	void setLToneKeyShift(char l);
	void setUToneFineTune(char u);
	void setLToneFineTune(char l);
	void setBenderRange(unsigned char br);
	void setAftertouchPitchBend(char ap);
	void setPortamentoTime(unsigned char pt);
	void setOutputMode(OutputMode om);
	void setReverbType(ReverbType rt);
	void setReverbBalance(unsigned char rb);
	void setTotalVolume(unsigned char tv);
	void setToneBalance(unsigned char tb);
	void setChaseMode(ChaseMode cm);
	void setChaseLevel(unsigned char cl);
	void setChaseTime(unsigned char ct);
	void setTransmitCHBasic(bool b);
	void setTransmitCH(unsigned char ch);
	void setSeparateModeReceiveCHOn(bool on);
	void setSeparateModeReceiveCH(unsigned char ch);
	void setTransmitProgramChangeOn(bool on);
	void setTransmitProgramChange(unsigned char pc);
	void setChaseSwitch(bool cs);
	void setPortamentoSwitch(bool ps);
	void setSeparateSwitch(bool ss);
	void setTransmitBankSelectOn(bool on);
	void setTransmitBankSelect(unsigned char bs);
	void setLowerOn(bool lo);
	void setUpperOn(bool uo);
	void setLowerPartial1On(bool lp1);
	void setLowerPartial2On(bool lp2);
	void setUpperPartial1On(bool up1);
	void setUpperPartial2On(bool up2);

	// Access methods
	const std::string& getPatchName() const;
	std::string& getPatchName();
	KeyMode getKeyMode() const;
	unsigned char getSplitPoint() const;
	ULSet getPortamentoMode() const;
	ULSet getHoldMode() const;
	char getUToneKeyShift() const;
	char getLToneKeyShift() const;
	char getUToneFineTune() const;
	char getLToneFineTune() const;
	unsigned char getBenderRange() const;
	char getAftertouchPitchBend() const;
	unsigned char getPortamentoTime() const;
	OutputMode getOutputMode() const;
	ReverbType getReverbType() const;
	unsigned char getReverbBalance() const;
	unsigned char getTotalVolume() const;
	unsigned char getToneBalance() const;
	ChaseMode getChaseMode() const;
	unsigned char getChaseLevel() const;
	unsigned char getChaseTime() const;
	bool getTransmitCHBasic() const;
	unsigned char getTransmitCH() const;
	bool getSeparateModeReceiveCHOn() const;
	unsigned char getSeparateModeReceiveCH() const;
	bool getTransmitProgramChangeOn() const;
	unsigned char getTransmitProgramChange() const;
	bool getChaseSwitch() const;
	bool getPortamentoSwitch() const;
	bool getSeparateSwitch() const;
	bool getTransmitBankSelectOn() const;
	unsigned char getTransmitBankSelect() const;
	bool getLowerOn() const;
	bool getUpperOn() const;
	bool getLowerPartial1On() const;
	bool getLowerPartial2On() const;
	bool getUpperPartial1On() const;
	bool getUpperPartial2On() const;

	// Dump method
	void dump(Address& a, unsigned length, const unsigned char* data);

	// Print methods
	std::string KeyModeStr(KeyMode km) const;
	std::string KeyModeStr() const;
	std::string ULSetStr(ULSet uls) const;
	std::string OutputModeStr(OutputMode om) const;
	std::string OutputModeStr() const;
	std::string ReverbTypeStr(ReverbType rt) const;
	std::string ReverbTypeStr() const;
	std::string ChaseModeStr(ChaseMode cm) const;
	std::string ChaseModeStr() const;
	std::string pitchStr(int p) const;
	void print(int m) const;
};

#endif
 
