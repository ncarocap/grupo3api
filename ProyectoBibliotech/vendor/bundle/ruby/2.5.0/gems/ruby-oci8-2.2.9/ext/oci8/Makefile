
SHELL = /bin/sh

# V=0 quiet, V=1 verbose.  other values don't work.
V = 0
Q1 = $(V:1=)
Q = $(Q1:0=@)
ECHO1 = $(V:1=@ :)
ECHO = $(ECHO1:0=@ echo)
NULLCMD = :

#### Start of system configuration section. ####

srcdir = .
topdir = /usr/include/ruby-2.5.0
hdrdir = $(topdir)
arch_hdrdir = /usr/include/x86_64-linux-gnu/ruby-2.5.0
PATH_SEPARATOR = :
VPATH = $(srcdir):$(arch_hdrdir)/ruby:$(hdrdir)/ruby
prefix = $(DESTDIR)/usr
rubysitearchprefix = $(sitearchlibdir)/$(RUBY_BASE_NAME)
rubyarchprefix = $(archlibdir)/$(RUBY_BASE_NAME)
rubylibprefix = $(libdir)/$(RUBY_BASE_NAME)
exec_prefix = $(prefix)
vendorarchhdrdir = $(sitearchincludedir)/$(RUBY_VERSION_NAME)/vendor_ruby
sitearchhdrdir = $(sitearchincludedir)/$(RUBY_VERSION_NAME)/site_ruby
rubyarchhdrdir = $(archincludedir)/$(RUBY_VERSION_NAME)
vendorhdrdir = $(rubyhdrdir)/vendor_ruby
sitehdrdir = $(rubyhdrdir)/site_ruby
rubyhdrdir = $(includedir)/$(RUBY_VERSION_NAME)
vendorarchdir = $(rubysitearchprefix)/vendor_ruby/$(ruby_version)
vendorlibdir = $(vendordir)/$(ruby_version)
vendordir = $(rubylibprefix)/vendor_ruby
sitearchdir = $(DESTDIR)./.gem.20210409-20007-8ep40e
sitelibdir = $(DESTDIR)./.gem.20210409-20007-8ep40e
sitedir = $(DESTDIR)/usr/local/lib/site_ruby
rubyarchdir = $(rubyarchprefix)/$(ruby_version)
rubylibdir = $(rubylibprefix)/$(ruby_version)
sitearchincludedir = $(includedir)/$(sitearch)
archincludedir = $(includedir)/$(arch)
sitearchlibdir = $(libdir)/$(sitearch)
archlibdir = $(libdir)/$(arch)
ridir = $(datarootdir)/$(RI_BASE_NAME)
mandir = $(datarootdir)/man
localedir = $(datarootdir)/locale
libdir = $(exec_prefix)/lib
psdir = $(docdir)
pdfdir = $(docdir)
dvidir = $(docdir)
htmldir = $(docdir)
infodir = $(datarootdir)/info
docdir = $(datarootdir)/doc/$(PACKAGE)
oldincludedir = $(DESTDIR)/usr/include
includedir = $(prefix)/include
runstatedir = $(DESTDIR)/var/run
localstatedir = $(DESTDIR)/var
sharedstatedir = $(prefix)/com
sysconfdir = $(DESTDIR)/etc
datadir = $(datarootdir)
datarootdir = $(prefix)/share
libexecdir = $(exec_prefix)/libexec
sbindir = $(exec_prefix)/sbin
bindir = $(exec_prefix)/bin
archdir = $(rubyarchdir)


CC = gcc
CXX = g++
LIBRUBY = $(LIBRUBY_SO)
LIBRUBY_A = lib$(RUBY_SO_NAME)-static.a
LIBRUBYARG_SHARED = -l$(RUBY_SO_NAME)
LIBRUBYARG_STATIC = -l$(RUBY_SO_NAME)-static
empty =
OUTFLAG = -o $(empty)
COUTFLAG = -o $(empty)
CSRCFLAG = $(empty)

RUBY_EXTCONF_H = extconf.h
cflags   = $(optflags) $(debugflags) $(warnflags)
cxxflags = $(optflags) $(debugflags) $(warnflags)
optflags = -O3
debugflags = -ggdb3
warnflags = -Wall -Wextra -Wno-unused-parameter -Wno-parentheses -Wno-long-long -Wno-missing-field-initializers -Wno-tautological-compare -Wno-parentheses-equality -Wno-constant-logical-operand -Wno-self-assign -Wunused-variable -Wimplicit-int -Wpointer-arith -Wwrite-strings -Wdeclaration-after-statement -Wimplicit-function-declaration -Wdeprecated-declarations -Wmisleading-indentation -Wno-packed-bitfield-compat -Wsuggest-attribute=noreturn -Wsuggest-attribute=format -Wimplicit-fallthrough=0 -Wduplicated-cond -Wrestrict
CCDLFLAGS = -fPIC
CFLAGS   = $(CCDLFLAGS) -g -O2 -fdebug-prefix-map=/build/ruby2.5-ADJMZV/ruby2.5-2.5.5=. -fstack-protector-strong -Wformat -Werror=format-security -fPIC -I/opt/oracle/product/18c/dbhomeXE/rdbms/public -Wall $(ARCH_FLAG)
INCFLAGS = -I. -I$(arch_hdrdir) -I$(hdrdir)/ruby/backward -I$(hdrdir) -I$(srcdir)
DEFS     = 
CPPFLAGS = -DRUBY_EXTCONF_H=\"$(RUBY_EXTCONF_H)\" -Wdate-time -D_FORTIFY_SOURCE=2 $(DEFS) $(cppflags)
CXXFLAGS = $(CCDLFLAGS) -g -O2 -fdebug-prefix-map=/build/ruby2.5-ADJMZV/ruby2.5-2.5.5=. -fstack-protector-strong -Wformat -Werror=format-security $(ARCH_FLAG)
ldflags  = -L. -Wl,-z,relro -Wl,-z,now -fstack-protector -rdynamic -Wl,-export-dynamic
dldflags = -Wl,-z,relro -Wl,-z,now -Wl,--compress-debug-sections=zlib 
ARCH_FLAG = 
DLDFLAGS = $(ldflags) $(dldflags) $(ARCH_FLAG)
LDSHARED = $(CC) -shared
LDSHAREDXX = $(CXX) -shared
AR = ar
EXEEXT = 

RUBY_INSTALL_NAME = $(RUBY_BASE_NAME)2.5
RUBY_SO_NAME = ruby-2.5
RUBYW_INSTALL_NAME = 
RUBY_VERSION_NAME = $(RUBY_BASE_NAME)-$(ruby_version)
RUBYW_BASE_NAME = rubyw
RUBY_BASE_NAME = ruby

arch = x86_64-linux-gnu
sitearch = $(arch)
ruby_version = 2.5.0
ruby = $(bindir)/$(RUBY_BASE_NAME)2.5
RUBY = $(ruby)
ruby_headers = $(hdrdir)/ruby.h $(hdrdir)/ruby/backward.h $(hdrdir)/ruby/ruby.h $(hdrdir)/ruby/defines.h $(hdrdir)/ruby/missing.h $(hdrdir)/ruby/intern.h $(hdrdir)/ruby/st.h $(hdrdir)/ruby/subst.h $(arch_hdrdir)/ruby/config.h $(RUBY_EXTCONF_H)

RM = rm -f
RM_RF = $(RUBY) -run -e rm -- -rf
RMDIRS = rmdir --ignore-fail-on-non-empty -p
MAKEDIRS = /bin/mkdir -p
INSTALL = /usr/bin/install -c
INSTALL_PROG = $(INSTALL) -m 0755
INSTALL_DATA = $(INSTALL) -m 644
COPY = cp
TOUCH = exit >

#### End of system configuration section. ####

preload = 
libpath = . $(archlibdir)
LIBPATH =  -L. -L$(archlibdir)
DEFFILE = 

CLEANFILES = mkmf.log
DISTCLEANFILES = 
DISTCLEANDIRS = 

extout = 
extout_prefix = 
target_prefix = 
LOCAL_LIBS = 
LIBS = $(LIBRUBYARG_SHARED)  -L/opt/oracle/product/18c/dbhomeXE/lib -Wl,-rpath,/opt/oracle/product/18c/dbhomeXE/lib -lclntsh -lpthread -lgmp -ldl -lcrypt -lm   -lc
ORIG_SRCS = apiwrap.c attr.c bind.c connection_pool.c encoding.c env.c error.c hook_funcs.c lob.c metadata.c object.c oci8.c oci8lib.c ocidatetime.c ocihandle.c ocinumber.c oradate.c oranumber_util.c plthook_elf.c plthook_osx.c plthook_win32.c stmt.c thread_util.c util.c win32.c
SRCS = $(ORIG_SRCS) oci8lib.c env.c error.c oci8.c ocihandle.c connection_pool.c stmt.c bind.c metadata.c attr.c lob.c oradate.c ocinumber.c ocidatetime.c object.c apiwrap.c encoding.c oranumber_util.c thread_util.c util.c plthook_elf.c hook_funcs.c
OBJS = apiwrap.o attr.o bind.o connection_pool.o encoding.o env.o error.o hook_funcs.o lob.o metadata.o object.o oci8.o oci8lib.o ocidatetime.o ocihandle.o ocinumber.o oradate.o oranumber_util.o plthook_elf.o stmt.o thread_util.o util.o
HDRS = $(srcdir)/plthook.h $(srcdir)/thread_util.h $(srcdir)/extconf.h $(srcdir)/apiwrap.h $(srcdir)/oci8.h $(srcdir)/oranumber_util.h
LOCAL_HDRS = 
TARGET = oci8lib_250
TARGET_NAME = oci8lib_250
TARGET_ENTRY = Init_$(TARGET_NAME)
DLLIB = $(TARGET).so
EXTSTATIC = 
STATIC_LIB = 

TIMESTAMP_DIR = .
BINDIR        = $(bindir)
RUBYCOMMONDIR = $(sitedir)$(target_prefix)
RUBYLIBDIR    = $(sitelibdir)$(target_prefix)
RUBYARCHDIR   = $(sitearchdir)$(target_prefix)
HDRDIR        = $(rubyhdrdir)/ruby$(target_prefix)
ARCHHDRDIR    = $(rubyhdrdir)/$(arch)/ruby$(target_prefix)
TARGET_SO_DIR =
TARGET_SO     = $(TARGET_SO_DIR)$(DLLIB)
CLEANLIBS     = $(TARGET_SO) 
CLEANOBJS     = *.o  *.bak

all:    $(DLLIB)
static: $(STATIC_LIB)
.PHONY: all install static install-so install-rb
.PHONY: clean clean-so clean-static clean-rb

clean-static::
clean-rb-default::
clean-rb::
clean-so::
clean: clean-so clean-static clean-rb-default clean-rb
		-$(Q)$(RM) $(CLEANLIBS) $(CLEANOBJS) $(CLEANFILES) .*.time

distclean-rb-default::
distclean-rb::
distclean-so::
distclean-static::
distclean: clean distclean-so distclean-static distclean-rb-default distclean-rb
		-$(Q)$(RM) Makefile $(RUBY_EXTCONF_H) conftest.* mkmf.log
		-$(Q)$(RM) core ruby$(EXEEXT) *~ $(DISTCLEANFILES)
		-$(Q)$(RMDIRS) $(DISTCLEANDIRS) 2> /dev/null || true

realclean: distclean
install: install-so install-rb

install-so: $(DLLIB) $(TIMESTAMP_DIR)/.sitearchdir.time
	$(INSTALL_PROG) $(DLLIB) $(RUBYARCHDIR)
clean-static::
	-$(Q)$(RM) $(STATIC_LIB)
install-rb: pre-install-rb do-install-rb install-rb-default
install-rb-default: pre-install-rb-default do-install-rb-default
pre-install-rb: Makefile
pre-install-rb-default: Makefile
do-install-rb:
do-install-rb-default:
pre-install-rb-default:
	@$(NULLCMD)
$(TIMESTAMP_DIR)/.sitearchdir.time:
	$(Q) $(MAKEDIRS) $(@D) $(RUBYARCHDIR)
	$(Q) $(TOUCH) $@

site-install: site-install-so site-install-rb
site-install-so: install-so
site-install-rb: install-rb

.SUFFIXES: .c .m .cc .mm .cxx .cpp .o .S

.cc.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cc.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.mm.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.mm.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.cxx.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cxx.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.cpp.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cpp.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.c.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.c.S:
	$(ECHO) translating $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.m.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.m.S:
	$(ECHO) translating $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

$(TARGET_SO): $(OBJS) Makefile
	$(ECHO) linking shared-object $(DLLIB)
	-$(Q)$(RM) $(@)
	$(Q) $(LDSHARED) -o $@ $(OBJS) $(LIBPATH) $(DLDFLAGS) $(LOCAL_LIBS) $(LIBS)



###
$(OBJS): $(RUBY_EXTCONF_H)

Makefile: $(srcdir)/extconf.rb $(srcdir)/oraconf.rb
	$(RUBY) $(srcdir)/extconf.rb
oci8lib.o: $(srcdir)/oci8lib.c $(srcdir)/oci8.h apiwrap.h Makefile
env.o: $(srcdir)/env.c $(srcdir)/oci8.h apiwrap.h Makefile
error.o: $(srcdir)/error.c $(srcdir)/oci8.h apiwrap.h Makefile
oci8.o: $(srcdir)/oci8.c $(srcdir)/oci8.h apiwrap.h Makefile
ocihandle.o: $(srcdir)/ocihandle.c $(srcdir)/oci8.h apiwrap.h Makefile
connection_pool.o: $(srcdir)/connection_pool.c $(srcdir)/oci8.h apiwrap.h Makefile
stmt.o: $(srcdir)/stmt.c $(srcdir)/oci8.h apiwrap.h Makefile
bind.o: $(srcdir)/bind.c $(srcdir)/oci8.h apiwrap.h Makefile
metadata.o: $(srcdir)/metadata.c $(srcdir)/oci8.h apiwrap.h Makefile
attr.o: $(srcdir)/attr.c $(srcdir)/oci8.h apiwrap.h Makefile
lob.o: $(srcdir)/lob.c $(srcdir)/oci8.h apiwrap.h Makefile
oradate.o: $(srcdir)/oradate.c $(srcdir)/oci8.h apiwrap.h Makefile
ocinumber.o: $(srcdir)/ocinumber.c $(srcdir)/oci8.h apiwrap.h Makefile
ocidatetime.o: $(srcdir)/ocidatetime.c $(srcdir)/oci8.h apiwrap.h Makefile
object.o: $(srcdir)/object.c $(srcdir)/oci8.h apiwrap.h Makefile
apiwrap.o: $(srcdir)/apiwrap.c $(srcdir)/oci8.h apiwrap.h Makefile
encoding.o: $(srcdir)/encoding.c $(srcdir)/oci8.h apiwrap.h Makefile
oranumber_util.o: $(srcdir)/oranumber_util.c $(srcdir)/oci8.h apiwrap.h Makefile
thread_util.o: $(srcdir)/thread_util.c $(srcdir)/oci8.h apiwrap.h Makefile
util.o: $(srcdir)/util.c $(srcdir)/oci8.h apiwrap.h Makefile
plthook_elf.o: $(srcdir)/plthook_elf.c $(srcdir)/oci8.h apiwrap.h Makefile
hook_funcs.o: $(srcdir)/hook_funcs.c $(srcdir)/oci8.h apiwrap.h Makefile
apiwrap.c apiwrap.h: $(srcdir)/apiwrap.c.tmpl $(srcdir)/apiwrap.h.tmpl $(srcdir)/apiwrap.yml $(srcdir)/apiwrap.rb
	$(RUBY) $(srcdir)/apiwrap.rb
