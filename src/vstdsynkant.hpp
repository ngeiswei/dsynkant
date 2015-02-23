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

#include <audioeffectx.h>

namespace dsynkant {

class VSTDSynkant : public AudioEffectX
{
public:
	DSynkant dsynkant;

	VstEvents* events;			// midi events

	VSTDSynkant(audioMasterCallback audioMaster,
	            long numPrograms, long numParams);
	~VSTDSynkant();
	void process (float **inputs, float **outputs, long sampleFrames);
	void processReplacing (float **inputs, float **outputs, long sampleFrames);
	long dispatcher(long opCode, long index, long value, void *ptr, float opt);
	void setParameter (long index, float value);
	float getParameter (long index);
	void getParameterName (long index, char *text);
	void getParameterDisplay (long index, char *text);
};

} // ~namespace dsynkant

#endif
