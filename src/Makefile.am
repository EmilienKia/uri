
AM_CFLAGS =\
	 -Wall\
	 -g


lib_LTLIBRARIES = liburi.la

liburi_la_SOURCES =  \
	uri.cpp \
	uri_builder.cpp \
	uri_errors.cpp \
	detail/algorithm.hpp \
	detail/grammar.hpp \
	detail/uri_advance_parts.hpp \
	detail/uri_advance_parts.cpp \
	detail/uri_normalize.hpp \
	detail/uri_normalize.cpp \
	detail/uri_parse.hpp \
	detail/uri_parse.cpp \
	detail/uri_parse_authority.hpp \
	detail/uri_parse_authority.cpp \
	detail/uri_percent_encode.hpp \
	detail/uri_resolve.hpp \
	detail/uri_resolve.cpp

liburi_la_CPPFLAGS = -I$(top_srcdir)/include


