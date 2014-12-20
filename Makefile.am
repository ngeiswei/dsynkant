SUBDIRS = doc src


# make a small distribution with just one DSSI plugin
%.dist:
	mkdir $*.dist
	mkdir $*.dist/src
	cp -R src/common $*.dist/src/common
	cp -R src/components $*.dist/src/components
#	cp -R src/gui-components $*.dist/src/gui-components
	cp -R src/$* $*.dist/src/$*
	cp $*.dist/src/$*/README.$* $*.dist/README
	echo "SUBDIRS = common components $*" > $*.dist/src/Makefile.am
	cp Makefile.am $*.dist/Makefile.am
	cp configure.ac $*.dist/configure.ac
	cp AUTHORS NEWS ChangeLog $*.dist/
	touch $*.dist/NEWS $*.dist/README $*.dist/ChangeLog
	perl -pi -e 's/AC_CONFIG_FILES.*/AC_CONFIG_FILES\(\[Makefile src\/Makefile src\/common\/Makefile src\/components\/Makefile src\/'$*'\/Makefile\]\)/' $*.dist/configure.ac
	perl -pi -e 's/ll-plugins/'$*'/g' $*.dist/configure.ac
	cd $*.dist && libtoolize --copy --force	
	cd $*.dist && aclocal
	cd $*.dist && automake -a -c
	cd $*.dist && autoconf
	cd $*.dist && ./configure
	cd $*.dist && make dist
	mv $*.dist/$*-*.tar.gz .
	rm -rf $*.dist

EXTRA_DIST = reconf

