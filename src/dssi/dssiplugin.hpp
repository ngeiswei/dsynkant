/****************************************************************************
    
    dssiplugin.hpp - a class and functions that should make it easier to
                     write DSSI plugins in C++
    
    Copyright (C) 2005  Lars Luthman <larsl@users.sourceforge.net>
    
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

#ifndef DSSIPLUGIN_HPP
#define DSSIPLUGIN_HPP

#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#include <dssi.h>


using namespace std;


/** This is a base class for DSSI plugins. It has default implementations for
    all functions, so you only have to implement the functions that you need
    (for example run_synth()). Any subclass must have a constructor that takes
    a single unsigned long as parameter, otherwise it will not work with the
    template function register_dssi(). */
class DSSIPlugin {
public:
  
  /** A virtual destructor is needed since we have virtual member functions. */
  virtual ~DSSIPlugin() { }
  
  /** This function copies the pointer @c data_location to the port array. */
  virtual void connect_port(unsigned long port, LADSPA_Data* data_location) {
    m_ports[port] = data_location;
  }
  /** This function does nothing. Override it if you need to do something
      on activation. */
  virtual void activate() { }
  /** This function calls run_synth() with no MIDI events (just like the DSSI
      spec says it should) */
  virtual void run(unsigned long sample_count) {
    run_synth(sample_count, NULL, 0);
  }
  /** This function does nothing. Override it if you need to do something on
      deactivation. */
  virtual void deactivate() { }
  /** This function does nothing. Override it if you use configuration keys. */
  virtual char* configure(const char* key, const char* value) { return NULL; }
  /** This function does nothing. You most likely want to override it. */
  virtual void run_synth(unsigned long sample_count, snd_seq_event_t* events,
			 unsigned long event_count) { }
  /** This function always returns @c DSSI_NONE. If you want to map MIDI
      controllers to your control ports you will need to override it. */
  virtual int get_midi_controller_for_port(unsigned long port) { 
    return DSSI_NONE;
  }
  /** This function allows the host to select the synth program. */
  virtual void select_program(unsigned long bank, unsigned long program) { }
  /** This function returns the program with the given index or NULL if there
      is no such program. */
  virtual const DSSI_Program_Descriptor* get_program(unsigned long index) {
    return NULL;
  }
  
  /** This vector holds the pointers to the port buffers for this plugin
      instance. */
  vector<LADSPA_Data*> m_ports;
  
protected:
  
  
};


/** A helper class that stores info about a DSSI port. You should not need
    to use this class, it's only for internal use. */
struct DSSIPort {
  DSSIPort(LADSPA_PortDescriptor descriptor, const string& name, 
	   const LADSPA_PortRangeHint& hint)
    : m_descriptor(descriptor), m_name(name), m_hint(hint) { }
  DSSIPort(LADSPA_PortDescriptor descriptor, const string& name)
    : m_descriptor(descriptor), m_name(name) {
    memset(&m_hint, 0, sizeof(LADSPA_PortRangeHint));
  }

  LADSPA_PortDescriptor m_descriptor;
  string m_name;
  LADSPA_PortRangeHint m_hint;
};


/** This class should be passed as the last parameter to the register_dssi()
    function to specify the number and types of ports for your DSSI plugin. */
struct DSSIPortList : public vector<DSSIPort> {
  int add_port(LADSPA_PortDescriptor descriptor, const string& name,
		const LADSPA_PortRangeHint& hint) {
    push_back(DSSIPort(descriptor, name, hint));
    return size() - 1;
  }
  int add_port(LADSPA_PortDescriptor descriptor, const string& name) {
    push_back(DSSIPort(descriptor, name));
    return size() - 1;
  }
  int add_port(LADSPA_PortDescriptor descriptor, const string name,
		LADSPA_PortRangeHintDescriptor rh_desc,
		LADSPA_Data lower_bound, LADSPA_Data upper_bound) {
    LADSPA_PortRangeHint prh = { rh_desc, lower_bound, upper_bound };
    push_back(DSSIPort(descriptor, name, prh));
    return size() - 1;
  }
};


void connect_port(LADSPA_Handle instance, unsigned long port, 
		  LADSPA_Data* data_location);
void activate(LADSPA_Handle instance);
void run(LADSPA_Handle instance, unsigned long sample_count);
void deactivate(LADSPA_Handle instance);
char* configure(LADSPA_Handle instance, const char* key, const char* value);
void run_synth(LADSPA_Handle instance, unsigned long sample_count, 
	       snd_seq_event_t* events, unsigned long event_count);
int get_midi_controller_for_port(LADSPA_Handle instance, unsigned long port);
void select_program(LADSPA_Handle instance, unsigned long bank,
		    unsigned long program);
const DSSI_Program_Descriptor *get_program(LADSPA_Handle instance,
					   unsigned long index);


/** This template function is instantiated for each plugin class and used as the
    instantiation function. */
template <class T>
LADSPA_Handle create_plugin_instance(const LADSPA_Descriptor* descriptor,
				     unsigned long sample_rate) {
  T* t = new T(sample_rate);
  t->m_ports.resize(descriptor->PortCount, NULL);
  return reinterpret_cast<LADSPA_Descriptor*>(t);
}


/** This template function is instantiated for each plugin class and used as
    the cleanup function. */
template <class T>
void delete_plugin_instance(LADSPA_Handle instance) {
  delete reinterpret_cast<DSSIPlugin*>(instance);
}


/** Hacky hacky. These functions are defined as "weak" (a GCC attribute) so that
    they can be overridden in the plugin library, without breaking everything
    if they are _not_ overridden. This function will be called when the library
    is loaded, so this is where you can put your calls to register_dssi(). */
void initialise() __attribute__ ((weak));

/** @ see initialise() */
void finalise() __attribute__ ((weak));

/** This function returns the global vector of DSSI_Descriptors that is added 
    to by register_dssi(). It is used by the dssi_descriptor() function. */
vector<DSSI_Descriptor>& get_dssi_descriptors();


/** This is the function you should use to register your DSSI plugin class.
    It should be called when the library is loaded, so you can define an
    initialise() function and put it there. Since this is a template function
    but the template type isn't one of the parameters, you need to call it
    like this:
    
    register_dssi<MyPluginClass>(666, "my_plugin", 0, "My Plugin", "Me",
    "GPL", my_ports);
    
    @param uid The unique LADSPA ID for this plugin
    @param label The LADSPA label for this plugin
    @param properties The LADSPA properties for this plugin
    @param name The LADSPA name for this plugin
    @param maker Your name!
    @param copyright The copyright for this plugin (for example "GPL")
    @param ports The port list for this DSSI plugin.
*/
template <class T>
size_t register_dssi(unsigned long uid, const string& label, 
		     LADSPA_Properties properties, const string& name,
		     const string& maker, const string& copyright,
		     const DSSIPortList& ports) {
  
  DSSI_Descriptor descriptor;
  memset(&descriptor, 0, sizeof(DSSI_Descriptor));
  descriptor.DSSI_API_Version = 1;
  
  LADSPA_Descriptor* l_descriptor = 
    (LADSPA_Descriptor*)calloc(1, sizeof(LADSPA_Descriptor));
  descriptor.LADSPA_Plugin = l_descriptor;
  
  l_descriptor->UniqueID = uid;
  l_descriptor->Label = strdup(label.c_str());
  l_descriptor->Properties = properties;
  l_descriptor->Name = strdup(name.c_str());
  l_descriptor->Maker = strdup(maker.c_str());
  l_descriptor->Copyright = strdup(copyright.c_str());
  
  l_descriptor->PortCount = ports.size();
  LADSPA_PortDescriptor* port_desc = 
    (LADSPA_PortDescriptor*)calloc(ports.size(), sizeof(LADSPA_PortDescriptor));
  char** port_name = (char**)calloc(ports.size(), sizeof(const char*));
  LADSPA_PortRangeHint* port_hint = 
    (LADSPA_PortRangeHint*)calloc(ports.size(), sizeof(LADSPA_PortRangeHint));
  for (unsigned i = 0; i < ports.size(); ++i) {
    port_desc[i] = ports[i].m_descriptor;
    port_name[i] = strdup(ports[i].m_name.c_str());
    port_hint[i] = ports[i].m_hint;
  }
  l_descriptor->PortDescriptors = port_desc;
  l_descriptor->PortNames = port_name;
  l_descriptor->PortRangeHints = port_hint;
  
  l_descriptor->instantiate = &create_plugin_instance<T>;
  l_descriptor->cleanup = &delete_plugin_instance<T>;
  l_descriptor->connect_port = &connect_port;
  l_descriptor->activate = &activate;
  l_descriptor->run = &run;
  l_descriptor->deactivate = &deactivate;

  descriptor.configure = &configure;
  descriptor.run_synth = &run_synth;
  descriptor.get_midi_controller_for_port = &get_midi_controller_for_port;
  descriptor.get_program = &get_program;
  descriptor.select_program = &select_program;
  
  get_dssi_descriptors().push_back(descriptor);
  
  return get_dssi_descriptors().size() - 1;
}


/** A helper class that makes sure that the functions initialise() and 
    finalise() are called when the plugin library is loaded and unloaded.
    Only for internal use. */
struct DSSIInitialiseFinalise {
  DSSIInitialiseFinalise() { initialise(); }
  ~DSSIInitialiseFinalise() { finalise(); }
};


extern DSSIInitialiseFinalise g_dssi_init_fini_object;

#endif
