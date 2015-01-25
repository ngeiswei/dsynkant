/****************************************************************************
    
    DSynkant an emulator of the Roland D50 synthsizer

    engine.hpp

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

#ifndef __DSYNKANT_ENGINE_HPP
#define __DSYNKANT_ENGINE_HPP

#include "voice.hpp"

#include <set>

namespace dsynkant {

class DSynkant;

/**
 * The engine holds the information of each voice, state of the
 * frequency, volume, sample offset, etc. And provide the render of
 * each voice and the whole mix.
 */

class Engine {
private:
	DSynkant& _dsynkant;

	std::multiset<Voice> _voices;

public:
	Engine(DSynkant& ref);
	~Engine();

	//print method
	void print(int m) const;
};

} // ~namespace dsynkant

#endif
