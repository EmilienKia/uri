dnl Process this file with autoconf to produce a configure script.

AC_INIT(uri, 1.0)

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([aux-bin])

AM_INIT_AUTOMAKE([1.11 foreign subdir-objects])

AM_SILENT_RULES([yes])


AC_PROG_CXX
AX_CXX_COMPILE_STDCXX(17)


LT_INIT


AC_OUTPUT([
Makefile
include/Makefile
src/Makefile
network-uri.pc
])
