/****************************************************************************
    
    DSSI wrapper for DSynkant

    dssidsynkant.hpp

    Copyleft (c) 2015 Nil Geisweiller
 
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

#ifndef __DSYNKANT_VSTDSYNKANT_HPP
#define __DSYNKANT_VSTDSYNKANT_HPP

#include "public.sdk/source/vst2.x/audioeffectx.h"
#include "dsynkant/dsynkant.hpp"

namespace dsynkant {

class VSTDSynkant : public AudioEffectX
{
public:
	DSynkant dsynkant;

	VstEvents* events;			// midi events

	VSTDSynkant(audioMasterCallback audioMaster);
	~VSTDSynkant();

	// Process audio and events
	VstInt32 processEvents(VstEvents* events);
	void midi(unsigned char status, unsigned char byte1, unsigned char byte2);
	void process(float **inputs, float **outputs, VstInt32 sampleFrames);
	void processReplacing(float **inputs, float **outputs,
	                      VstInt32 sampleFrames);
	VstIntPtr dispatcher(VstInt32 opCode, VstInt32 index, VstIntPtr value,
	                     void *ptr, float opt);

	// // Access/modify parameter
	void setParameter(VstInt32 index, float value);
	float getParameter(VstInt32 index);
	void getParameterLabel(VstInt32 index, char *label);
	void getParameterName(VstInt32 index, char *text);
	void getParameterDisplay(VstInt32 index, char *text);

	// Plugin name, vendor and version
	bool getEffectName(char* name);
	bool getVendorString(char* text);
	bool getProductString(char* text);
	VstInt32 getVendorVersion();

	VstInt32 canDo(char* text);

	bool getOutputProperties(VstInt32 index, VstPinProperties* properties);

	/** TODO possibly implement the following methods

		void setProgram(VstInt32 program);
		void setProgramName(char *name);
		void getProgramName(char *name);
		void setSampleRate(float sampleRate);
		void setBlockSize(VstInt32 blockSize);
		void suspend();
		void resume();

		bool getProgramNameIndexed (VstInt32 category, VstInt32 index, char* text);
		bool copyProgram (VstInt32 destination);
	*/

private:
	// Midi status codes
	static const unsigned char NOTE_ON = 0x90;
	static const unsigned char NOTE_OFF = 0x80;

	void processEvent(VstEvent* event);
};

} // ~namespace dsynkant

#endif
