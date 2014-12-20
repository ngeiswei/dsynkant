/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    dsynkant.cpp

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

#include <stdio.h>
#include "dsynkant.hpp"

DSynkant::DSynkant() : _engine(this) {}

DSynkant::~DSynkant() {}

void DSynkant::audio_process(float* left_out, float* right_out,
                             unsigned long sample_count) {
    //printf("AUDIO_PROCESS\n");
    for(unsigned long i = 0; i < sample_count; i++) {
        left_out[i] = 0.0;
        right_out[i] = 0.0;
    }
}

void DSynkant::noteOn_process(int channel, int pitch, int velocity) {
    printf("NOTE_ON\n");
    printf("PRINT PATCH\n");
    _workPatch.print();
}

void DSynkant::noteOff_process(int channel, int pitch) {
    printf("NOTE OFF\n");
}

void DSynkant::sysex_process(unsigned length, unsigned char* data) {
    unsigned char command_ID;
    printf("SYSEX\n");
    for(unsigned i = 0; i < length; i++) printf("%X ", data[i]);
    printf("\n");
    //check if the sysex is for Roland D-50
    if(length > 5 && data[1] == 0x41 && data[3] == 0x14) {
        command_ID = data[4];
        switch(command_ID) {
        case COMMAND_DUMP_PATCH :
            printf("Dump patch\n");
            if(length > 8) {
                //check if the dump is for the working patch
                if(data[5] == 0x00) {
                    printf("DUMP WORKING PATCH\n");
                    Address a(data[6], data[7]);
                    _workPatch.dump(a,
                                    length - 8 - 1/*to ignore the last 0xF7*/, 
                                    &data[8]);
                    printf("PRINT PATCH\n");
                    _workPatch.print();
                }
                else {
                    printf("DUMP BANK\n");
                    _set.dump(length - 5, &data[5]);
                }
            }
            break;
        default :
            break;
        }
    }
}

//print method
void DSynkant::print() {
    printf("Set :\n");
    _set.print(2);
    printf("Working patch :\n");
    _workPatch.print(2);
    printf("State of the engine :\n");
    _engine.print(2);
}
