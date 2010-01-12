################################################################################
# File:     makefile
#
# Purpose:  Makefile for the b64 project, for the Arturius C/C++ Compiler Multiplexer
#           compiler, on Win32
#
# Created:  15th Feburary 2005
# Updated:  3rd August 2008
#
################################################################################


################################################################################
# Symbols

# Identification

COMP_TAG          =   ar
PROJ_TAG          =   b64
PROJ_VER_MAJOR    =   1
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR)

CC                  =   arcc.debug
CPPC                =   arcc.debug
AR                  =   lib
LD                  =   arld
RM                  =   del /f
CP                  =   copy
RC                  =   rc

# Directories

PROJ_BASE_DIR       =   ../..
PROJ_BIN_DIR        =   $(PROJ_BASE_DIR)/bin
PROJ_INCLUDE_DIR    =   $(PROJ_BASE_DIR)/include
PROJ_LIB_DIR        =   $(PROJ_BASE_DIR)/lib
PROJ_OBJ_DIR        =   .
PROJ_SRC_DIR        =   $(PROJ_BASE_DIR)/src
PROJ_MAPPINGS_DIR   =   $(PROJ_BASE_DIR)/mappings
PROJ_TESTS_DIR      =   $(PROJ_BASE_DIR)/test
PROJ_EXAMPLES_DIR   =   $(PROJ_BASE_DIR)/examples
PROJ_SAMPLES_DIR    =   $(PROJ_BASE_DIR)/samples

# Includes

INCLUDES_LEADER     =   

PROJ_INCLUDE        =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES     =   

CC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 \

CPPC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 -I"$(STLSOFT)/include"\
 \

3PTY_LIBS__DEBUG = \
 \

3PTY_LIBS__RELEASE = \
 \


LIB_PATHS =\
 \

LIBS_LEADER         =   

COMMON_LIB          =   

# #defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DB64_NO_IMPLICIT_LINK\
 \

COMMON_DEFS         =   -DWIN32 $(CMN_DEF_NO_IMPLICIT_LINK)

CC_DEFS             =   $(COMMON_DEFS)

CPPC_DEFS           =   $(COMMON_DEFS)

# Flags

CC_F_NOLOGO             =   
CC_F_COMPILE_ONLY       =   -c
CC_F_WARNING_MAX        =   --warning-level=maximum
CC_F_WARNING_ERR        =   --warnings-as-errors=on

CPPC_F_NOLOGO       =   
CPPC_F_COMPILE_ONLY =   -c
CPPC_F_WARNING_MAX  =   --warning-level=maximum
CPPC_F_WARNING_ERR  =   --warnings-as-errors=on
CPPC_F_EXCEPTIONS   =   --exception-handling=on
CPPC_F_RTTI         =   

CC_TOOL_FLAGS       =   --compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71,ow12 --announce-tools --active-compiler=vc/6 --announce-tool-commands

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CPPC_TOOL_FLAGS     =   --compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71 --announce-tools --active-compiler=vc/6 --announce-tool-commands

CPPC_FLAGS = \
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

# Arguments (= flags + defines + includes)

CC_ARGS_DEBUG = -D_DEBUG -UNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_RELEASE = -DNDEBUG -U_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_DEBUG = -D_DEBUG -UNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_RELEASE = -DNDEBUG -U_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

# archiver flags and arguments

AR_ARGS = 

# linker flags and arguments

LD_F_NOLOGO = 

LD_ARGS_DEBUG =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_RELEASE =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_DEBUG = $(PROJ_LIB_DIR)/$(PROJ_TAG_VER).$(COMP_TAG).debug.lib
TARGET_LIB_UN_DEBUG = $(PROJ_LIB_DIR)/$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_RELEASE = $(PROJ_LIB_DIR)/$(PROJ_TAG_VER).$(COMP_TAG).release.lib
TARGET_LIB_UN_RELEASE = $(PROJ_LIB_DIR)/$(PROJ_TAG).$(COMP_TAG).release.lib

TARGETS_LIBS =\
 $(TARGET_LIB_DEBUG)\
 $(TARGET_LIB_UN_DEBUG)\
 $(TARGET_LIB_RELEASE)\
 $(TARGET_LIB_UN_RELEASE)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_1_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).debug.exe
TARGET_TEST_C_1_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).release.exe
TARGET_TEST_CPP_1_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).release.exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_DEBUG)\
 $(TARGET_TEST_C_1_RELEASE)\
 $(TARGET_TEST_CPP_1_DEBUG)\
 $(TARGET_TEST_CPP_1_RELEASE)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_2_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_1_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_2_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_1_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_2_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_1_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_2_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).release.exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_DEBUG)\
 $(TARGET_EXAMPLE_C_2_DEBUG)\
 $(TARGET_EXAMPLE_C_1_RELEASE)\
 $(TARGET_EXAMPLE_C_2_RELEASE)\
 $(TARGET_EXAMPLE_CPP_1_DEBUG)\
 $(TARGET_EXAMPLE_CPP_2_DEBUG)\
 $(TARGET_EXAMPLE_CPP_1_RELEASE)\
 $(TARGET_EXAMPLE_CPP_2_RELEASE)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_CPP_1_DEBUG = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).sample.cpp.1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_1_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).release.exe
TARGET_SAMPLE_CPP_1_RELEASE = $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).sample.cpp.1.$(COMP_TAG).release.exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_DEBUG)\
 $(TARGET_SAMPLE_C_1_RELEASE)\
 $(TARGET_SAMPLE_CPP_1_DEBUG)\
 $(TARGET_SAMPLE_CPP_1_RELEASE)\
 \

########################################
# TARGETS

TARGETS = \
 $(TARGETS_LIBS)\
 $(TARGETS_TESTS)\
 $(TARGETS_EXAMPLES)\
 $(TARGETS_SAMPLES)\
 \

########################################
# OBJS_CORE

OBJ_CORE_b64__DEBUG = $(PROJ_OBJ_DIR)/b64.debug.obj

OBJS_CORE_DEBUG = \
 $(OBJ_CORE_b64__DEBUG)\
 \


OBJ_CORE_b64__RELEASE = $(PROJ_OBJ_DIR)/b64.release.obj

OBJS_CORE_RELEASE = \
 $(OBJ_CORE_b64__RELEASE)\
 \


OBJS_CORE =\
 $(OBJS_CORE_DEBUG)\
 $(OBJS_CORE_RELEASE)\
 \

########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_C_1_DEBUG = $(PROJ_OBJ_DIR)/test.c.1.debug.obj
OBJ_TEST_CPP_1_DEBUG = $(PROJ_OBJ_DIR)/test.cpp.1.debug.obj
OBJ_TEST_C_1_RELEASE = $(PROJ_OBJ_DIR)/test.c.1.release.obj
OBJ_TEST_CPP_1_RELEASE = $(PROJ_OBJ_DIR)/test.cpp.1.release.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_DEBUG)\
 $(OBJ_TEST_C_1_RELEASE)\
 $(OBJ_TEST_CPP_1_DEBUG)\
 $(OBJ_TEST_CPP_1_RELEASE)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_DEBUG = $(PROJ_OBJ_DIR)/example.c.1.debug.obj
OBJ_EXAMPLE_C_2_DEBUG = $(PROJ_OBJ_DIR)/example.c.2.debug.obj
OBJ_EXAMPLE_CPP_1_DEBUG = $(PROJ_OBJ_DIR)/example.cpp.1.debug.obj
OBJ_EXAMPLE_CPP_2_DEBUG = $(PROJ_OBJ_DIR)/example.cpp.2.debug.obj
OBJ_EXAMPLE_C_1_RELEASE = $(PROJ_OBJ_DIR)/example.c.1.release.obj
OBJ_EXAMPLE_C_2_RELEASE = $(PROJ_OBJ_DIR)/example.c.2.release.obj
OBJ_EXAMPLE_CPP_1_RELEASE = $(PROJ_OBJ_DIR)/example.cpp.1.release.obj
OBJ_EXAMPLE_CPP_2_RELEASE = $(PROJ_OBJ_DIR)/example.cpp.2.release.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_DEBUG)\
 $(OBJ_EXAMPLE_C_2_DEBUG)\
 $(OBJ_EXAMPLE_C_1_RELEASE)\
 $(OBJ_EXAMPLE_C_2_RELEASE)\
 $(OBJ_EXAMPLE_CPP_1_DEBUG)\
 $(OBJ_EXAMPLE_CPP_2_DEBUG)\
 $(OBJ_EXAMPLE_CPP_1_RELEASE)\
 $(OBJ_EXAMPLE_CPP_2_RELEASE)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_DEBUG = $(PROJ_OBJ_DIR)/sample.c.1.debug.obj
OBJ_SAMPLE_CPP_1_DEBUG = $(PROJ_OBJ_DIR)/sample.cpp.1.debug.obj
OBJ_SAMPLE_C_1_RELEASE = $(PROJ_OBJ_DIR)/sample.c.1.release.obj
OBJ_SAMPLE_CPP_1_RELEASE = $(PROJ_OBJ_DIR)/sample.cpp.1.release.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_DEBUG)\
 $(OBJ_SAMPLE_C_1_RELEASE)\
 $(OBJ_SAMPLE_CPP_1_DEBUG)\
 $(OBJ_SAMPLE_CPP_1_RELEASE)\
 \


########################################
# OBJS

OBJS = \
 $(OBJS_LIBS)\
 $(OBJS_TESTS)\
 $(OBJS_EXAMPLES)\
 $(OBJS_SAMPLES)\
 \

########################################
# SRC_CORE

LIB_CORE_b64_H = $(PROJ_INCLUDE_DIR)/b64/b64.h
LIB_CORE_implicit_link_H = $(PROJ_INCLUDE_DIR)/b64/implicit_link.h

LIB_CORE_b64_C = $(PROJ_SRC_DIR)/b64.c

########################################
# SRC_HEADERS

HEADERS_LIB	= \
 $(LIB_CORE_b64_H)\
 $(LIB_CORE_implicit_link_H)\
 \

HEADERS_MAPPING_CPP =\
 $(PROJ_INCLUDE_DIR)/b64/b64.hpp\
 \

########################################
# SRC_TESTS

SRC_TEST_C_1 = $(PROJ_TESTS_DIR)/c/test.c.1/test.c.1.c
SRC_TEST_CPP_1 = $(PROJ_TESTS_DIR)/cpp/test.cpp.1/test.cpp.1.cpp

########################################
# SRC_EXAMPLES

SRC_EXAMPLE_C_1 = $(PROJ_EXAMPLES_DIR)/c/example.c.1/example.c.1.c
SRC_EXAMPLE_C_2 = $(PROJ_EXAMPLES_DIR)/c/example.c.2/example.c.2.c
SRC_EXAMPLE_CPP_1 = $(PROJ_EXAMPLES_DIR)/cpp/example.cpp.1/example.cpp.1.cpp
SRC_EXAMPLE_CPP_2 = $(PROJ_EXAMPLES_DIR)/cpp/example.cpp.2/example.cpp.2.cpp

########################################
# SRC_SAMPLES

SRC_SAMPLE_C_1 = $(PROJ_SAMPLES_DIR)/c/sample.c.1/sample.c.1.c
SRC_SAMPLE_CPP_1 = $(PROJ_SAMPLES_DIR)/cpp/sample.cpp.1/sample.cpp.1.cpp

################################################################################
# External Targets (invokable by make)

all:                build.all

check.lib.dir:
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)

build.libs.core:    check.lib.dir $(TARGETS_LIBS)

build.libs.com:     makefile

build.libs.dotnet:  makefile

build.libs:         build.libs.core build.libs.com build.libs.dotnet

build.examples:     check.bin.dir $(TARGETS_EXAMPLES)

build.samples:      check.bin.dir $(TARGETS_SAMPLES)

build.test:         check.bin.dir $(TARGETS_TESTS)

build.all:          build.libs build.examples build.samples build.test

build:              build.all

compile:            $(OBJS)


test_:              makefile
	$(TARGET_TEST_C_1_DEBUG) --unittest
	$(TARGET_TEST_C_1_RELEASE) --unittest
	$(TARGET_TEST_CPP_1_DEBUG) --unittest
	$(TARGET_TEST_CPP_1_RELEASE) --unittest

test:		build.all test_

test.all:	test

test-all:	test.all	# backwards compatibility


usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean.libs.core:
	@-$(RM) $(TARGET_LIB_DEBUG)
	@-$(RM) $(TARGET_LIB_UN_DEBUG)
	@-$(RM) $(TARGET_LIB_RELEASE)
	@-$(RM) $(TARGET_LIB_UN_RELEASE)
	@-$(RM) $(OBJ_CORE_b64__DEBUG)
	@-$(RM) $(OBJ_CORE_b64__RELEASE)

clean.libs.com:	makefile

clean.libs.dotnet:	makefile

clean.libs:         clean.libs.core clean.libs.com clean.libs.dotnet

clean.test:
	@-$(RM) $(TARGET_TEST_C_1_DEBUG)
	@-$(RM) $(TARGET_TEST_C_1_RELEASE)
	@-$(RM) $(TARGET_TEST_CPP_1_DEBUG)
	@-$(RM) $(TARGET_TEST_CPP_1_RELEASE)
	@-$(RM) $(OBJ_TEST_C_1_DEBUG)
	@-$(RM) $(OBJ_TEST_C_1_RELEASE)
	@-$(RM) $(OBJ_TEST_CPP_1_DEBUG)
	@-$(RM) $(OBJ_TEST_CPP_1_RELEASE)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_2_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_1_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_2_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_1_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_2_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_1_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_2_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_RELEASE)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_C_1_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_C_1_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_C_1_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_RELEASE)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core


$(TARGET_LIB_UN_DEBUG): $(TARGET_LIB_DEBUG)
	@$(CP) $(TARGET_LIB_DEBUG) $@

$(TARGET_LIB_DEBUG): $(OBJS_CORE_DEBUG) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_DEBUG)

$(OBJ_CORE_b64__DEBUG): $(PROJ_SRC_DIR)/b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)/b64.c


$(TARGET_LIB_UN_RELEASE): $(TARGET_LIB_RELEASE)
	@$(CP) $(TARGET_LIB_RELEASE) $@

$(TARGET_LIB_RELEASE): $(OBJS_CORE_RELEASE) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_RELEASE)

$(OBJ_CORE_b64__RELEASE): $(PROJ_SRC_DIR)/b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)/b64.c


########################################
# test

# C test client

$(TARGET_TEST_C_1_DEBUG):	$(OBJ_TEST_C_1_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_TEST_C_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_TEST_C_1_DEBUG):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_RELEASE):	$(OBJ_TEST_C_1_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_TEST_C_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_TEST_C_1_RELEASE):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_TEST_C_1)

# C++ test client

$(TARGET_TEST_CPP_1_DEBUG):	$(OBJ_TEST_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_TEST_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_TEST_CPP_1_DEBUG):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_1_RELEASE):	$(OBJ_TEST_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_TEST_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_TEST_CPP_1_RELEASE):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_TEST_CPP_1)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_DEBUG):	$(OBJ_EXAMPLE_C_1_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_1_DEBUG):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_DEBUG):	$(OBJ_EXAMPLE_C_2_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_2_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_2_DEBUG):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_RELEASE):	$(OBJ_EXAMPLE_C_1_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_1_RELEASE):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_RELEASE):	$(OBJ_EXAMPLE_C_2_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_2_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_2_RELEASE):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_2)

# C++ example client

$(TARGET_EXAMPLE_CPP_1_DEBUG):	$(OBJ_EXAMPLE_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_1_DEBUG):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_DEBUG):	$(OBJ_EXAMPLE_CPP_2_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_2_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_2_DEBUG):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_RELEASE):	$(OBJ_EXAMPLE_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_1_RELEASE):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_RELEASE):	$(OBJ_EXAMPLE_CPP_2_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_2_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_2_RELEASE):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_2)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_DEBUG):	$(OBJ_SAMPLE_C_1_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_C_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_C_1_DEBUG):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_1_RELEASE):	$(OBJ_SAMPLE_C_1_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_C_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_C_1_RELEASE):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_C_1)

# C++ sample client

$(TARGET_SAMPLE_CPP_1_DEBUG):	$(OBJ_SAMPLE_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_CPP_1_DEBUG):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_1_RELEASE):	$(OBJ_SAMPLE_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_CPP_1_RELEASE):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_CPP_1)

################################################################################
