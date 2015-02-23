/****************************************************************************
    
    DSSI wrapper for DSynkant

    dssidsynkant.cpp

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

#include "vstdsynkant.hpp"

using namespace dsynkant;

// Main function

#ifdef __GNUC__ 
AEffect* main_plugin (audioMasterCallback audioMaster) asm ("main");
#define main main_plugin
#else
AEffect *main (audioMasterCallback audioMaster);
#endif

AEffect *main (audioMasterCallback audioMaster)
{ 
	VSTDSynkant vst_dsynkant(audioMaster, 1, 0);
	return vst_dsynkant.getAeffect();
}

// Plugin implementation

VSTDSynkant::VSTDSynkant(audioMasterCallback audioMaster,
                         long numPrograms, long numParams)
	: AudioEffectX(audioMaster, numPrograms, numParams)
{

	// Plugin id
	setUniqueID((int)'DSynkant');

	// stereo output
	setNumInputs(0);	
	setNumOutputs(2);	

	// init
	events = 0;
	hasVu();
	canProcessReplacing();
}

VSTDSynkant::~VSTDSynkant()
{
}

void VSTDSynkant::process(float **inputs, float **outputs, long sampleFrames)
{
	
	int i, cue, block;
	VstMidiEvent* e;
	
	// outputs buffers
	float* p1 = outputs[0];
	float* p2 = outputs[1];

	// process audio on midi events
	if (events)
	{

		cue = 0;
		for (i = 0; i < events->numEvents; i++)
		{
			e = (VstMidiEvent*) events->events[i];
			if (e->type == kVstMidiType)
			{
				block = e->deltaFrames - cue;
				if (block > 0) 
				{
					synth->process(p1, p2, block);
					p1 += block;
					p2 += block;
				}
				// TODO use dsynkant here
				synth->midiInput(
					e->midiData[0] + (e->midiData[1] << 8) + (e->midiData[2] << 16) );
				cue = e->deltaFrames;
			}
		}

	}

	// TODO use dsynkant here
	synth->process(p1, p2, sampleFrames - cue);

	// release events pointer
	events = 0;
	
}

void VSTDSynkant::processReplacing (float **inputs, float **outputs,
                                    long sampleFrames)
{
	process(inputs, outputs, sampleFrames);
}

long VSTDSynkant::dispatcher(long opCode, long index, long value,
                             void *ptr, float opt)
{
	int result = 0;

	switch (opCode)
	{

	case effSetSampleRate:  // Set sample rate
		// TODO use dsynkant
		synth->setRate((int)opt);
		break;
	case effProcessEvents:	// Process events
		events = (VstEvents*)ptr;
		result = 1;
		break;
	default:                // Default 
		result = AudioEffect::dispatcher(opCode, index, value, ptr, opt);
	}

	return result;

}

// Set param

void DSynkant::setParameter(long index, float value)
{
}

// Get param

float DSynkant::getParameter(long index)
{
}

// Get param name

void DSynkant::getParameterName (long index, char *text)
{
}

// Get param value

void DSynkant::getParameterDisplay (long index, char *text)
{
}
