SUBDIRS = commondef set engine

noinst_LTLIBRARIES = libdsynkant.la 
libdsynkant_la_SOURCES = dsynkant.cpp dsynkant.hpp
libdsynkant_la_LIBADD = commondef/libcommondef.la \
	set/libset.la engine/libengine.la
libdsynkant_la_CXXFLAGS = -Icommondef -Iset -Iengine

