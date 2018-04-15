# contrib/my_timeout/Makefile

MODULE_big = my_timeout
OBJS = my_timeout.o $(WIN32RES)
PGFILEDESC = "my_timeout - timeout sample code"
EXTENSION = my_timeout
DATA = my_timeout--1.0.sql

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/my_timeout
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
