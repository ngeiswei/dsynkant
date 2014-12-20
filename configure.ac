#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#AC_CONFIG_HEADERS

AC_PREREQ(2.59)
AC_INIT(dsynkant, 0.0.2)
AC_CONFIG_AUX_DIR(.)
AM_INIT_AUTOMAKE
AC_PROG_LIBTOOL
AC_CONFIG_SRCDIR([src/dssi/dssiplugin.cpp])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(DSSI, dssi >= 0.9)
PKG_CHECK_MODULES(LIBLO, liblo >= 0.18)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset pow strdup])

# Check for LADSPA and DSSI directories
AC_MSG_CHECKING([where to install DSSI plugins])
AC_ARG_WITH(dssi-dir, AS_HELP_STRING([--with-dssi-dir=DIR], [the directory that DSSI plugins should be installed in]), [dssidir=$withval], [dssidir=$libdir/dssi])
AC_MSG_RESULT($dssidir)
AC_SUBST(dssidir)
	
# Checking whether to build with optimisation flags or debug flags
debug_cflags="-g -O2 -Wall -Werror -ansi -pedantic"
opt_cflags="-O3 -fomit-frame-pointer -fstrength-reduce -funroll-loops -ffast-math -DNDEBUG -Wall -ansi -pedantic"
AC_MSG_CHECKING([whether to build with debugging info])
AC_ARG_ENABLE(debug, AS_HELP_STRING([--enable-debug], [build with debugging information (may slow down execution)]))
if test x$enable_debug == xyes; then
	CXXFLAGS=$debug_cflags
	CFLAGS=$debug_cflags
	AC_MSG_RESULT(yes)
else
	CFLAGS=$opt_cflags
	CXXFLAGS=$opt_cflags
	AC_MSG_RESULT(no)
fi

AC_CONFIG_FILES([Makefile
	doc/Makefile
	doc/manual/Makefile	
	doc/blueprint/Makefile
	src/Makefile
	src/dssi/Makefile
	src/dsynkant/Makefile
	src/dsynkant/commondef/Makefile
	src/dsynkant/set/Makefile
	src/dsynkant/engine/Makefile
])
AC_OUTPUT
