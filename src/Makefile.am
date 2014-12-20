SUBDIRS = dssi dsynkant

dssidir = @dssidir@
dssi_LTLIBRARIES = dssidsynkant.la
dssidsynkant_la_SOURCES = dssidsynkant.hpp dssidsynkant.cpp
dssidsynkant_la_LDFLAGS = -module -avoid-version
dssidsynkant_la_LIBADD = dssi/libdssi_plugin.la dsynkant/libdsynkant.la
dssidsynkant_la_CXXFLAGS = @DSSI_CFLAGS@ -Idssi -Idsynkant -DINSTALL_DIR=\"$(dssidir)\"


# Stolen from swh-plugins, makes stupid libtool versions go away
install-dssiLTLIBRARIES: $(dssi_LTLIBRARIES)
	mkdir -p $(DESTDIR)/$(dssidir)
	list='$(dssi_LTLIBRARIES)'; \
	for file in $$list; do \
	  sofile=`basename $$file .la`.so; \
	  $(INSTALL_PROGRAM) .libs/$$sofile $(DESTDIR)/$(dssidir); \
	done
