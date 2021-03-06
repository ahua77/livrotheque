################################################################################
# File:     makefile
#
# Purpose:  Makefile for the b64 project, for the Open Watcom C/C++ 1.2
#           compiler, on Win32
#
# Created:  15th Feburary 2005
# Updated:  3rd August 2008
#
################################################################################


################################################################################
# Symbols

# Identification

COMP_TAG          =   ow12
PROJ_TAG          =   b64
PROJ_VER_MAJOR    =   1
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR)

CC                  =   wcc386
CPPC                =   wpp386
AR                  =   wlib
LD                  =   wcl386
RM                  =   del /f
CP                  =   copy
RC                  =   rc

# Directories

PROJ_BASE_DIR       =   ..\..
PROJ_BIN_DIR        =   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR    =   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR        =   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR        =   .
PROJ_SRC_DIR        =   $(PROJ_BASE_DIR)\src
PROJ_MAPPINGS_DIR   =   $(PROJ_BASE_DIR)\mappings
PROJ_TESTS_DIR      =   $(PROJ_BASE_DIR)\test
PROJ_EXAMPLES_DIR   =   $(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR    =   $(PROJ_BASE_DIR)\samples

# Includes

INCLUDES_LEADER     =   

PROJ_INCLUDE        =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES     =   

CC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 \

3PTY_LIBS__ST_D = \
 \

3PTY_LIBS__ST_R = \
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

# Flags

CC_F_NOLOGO             =   -zq
CC_F_COMPILE_ONLY       =   
CC_F_WARNING_MAX        =   -w=9
CC_F_WARNING_ERR        =   -we

CC_TOOL_FLAGS       =   

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

# Arguments (= flags + defines + includes)

CC_ARGS_ST_D =  $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_R =  $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

# archiver flags and arguments

AR_ARGS = -q -c

# linker flags and arguments

LD_F_NOLOGO = 

LD_ARGS_ST_D = -zq $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_R = -zq $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_ST_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).debug.lib
TARGET_LIB_UN_ST_D = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_ST_R = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).lib
TARGET_LIB_UN_ST_R = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib

TARGETS_LIBS =\
 $(TARGET_LIB_ST_D)\
 $(TARGET_LIB_UN_ST_D)\
 $(TARGET_LIB_ST_R)\
 $(TARGET_LIB_UN_ST_R)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).debug.exe
TARGET_TEST_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_ST_D)\
 $(TARGET_TEST_C_1_ST_R)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_2_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).exe
TARGET_EXAMPLE_C_2_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_ST_D)\
 $(TARGET_EXAMPLE_C_2_ST_D)\
 $(TARGET_EXAMPLE_C_1_ST_R)\
 $(TARGET_EXAMPLE_C_2_ST_R)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_ST_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_1_ST_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_ST_D)\
 $(TARGET_SAMPLE_C_1_ST_R)\
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

OBJ_CORE_b64__ST_D = $(PROJ_OBJ_DIR)\b64.debug.obj

OBJS_CORE_ST_D_PM =\
 -+$(OBJ_CORE_b64__ST_D)\
 \

OBJS_CORE_ST_D = \
 $(OBJ_CORE_b64__ST_D)\
 \


OBJ_CORE_b64__ST_R = $(PROJ_OBJ_DIR)\b64.obj

OBJS_CORE_ST_R_PM =\
 -+$(OBJ_CORE_b64__ST_R)\
 \

OBJS_CORE_ST_R = \
 $(OBJ_CORE_b64__ST_R)\
 \


OBJS_CORE =\
 $(OBJS_CORE_ST_D)\
 $(OBJS_CORE_ST_R)\
 \

########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_C_1_ST_D = $(PROJ_OBJ_DIR)\test.c.1.debug.obj
OBJ_TEST_C_1_ST_R = $(PROJ_OBJ_DIR)\test.c.1.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_ST_D)\
 $(OBJ_TEST_C_1_ST_R)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_ST_D = $(PROJ_OBJ_DIR)\example.c.1.debug.obj
OBJ_EXAMPLE_C_2_ST_D = $(PROJ_OBJ_DIR)\example.c.2.debug.obj
OBJ_EXAMPLE_C_1_ST_R = $(PROJ_OBJ_DIR)\example.c.1.obj
OBJ_EXAMPLE_C_2_ST_R = $(PROJ_OBJ_DIR)\example.c.2.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_ST_D)\
 $(OBJ_EXAMPLE_C_2_ST_D)\
 $(OBJ_EXAMPLE_C_1_ST_R)\
 $(OBJ_EXAMPLE_C_2_ST_R)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_ST_D = $(PROJ_OBJ_DIR)\sample.c.1.debug.obj
OBJ_SAMPLE_C_1_ST_R = $(PROJ_OBJ_DIR)\sample.c.1.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_ST_D)\
 $(OBJ_SAMPLE_C_1_ST_R)\
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

LIB_CORE_b64_H = $(PROJ_INCLUDE_DIR)\b64\b64.h
LIB_CORE_implicit_link_H = $(PROJ_INCLUDE_DIR)\b64\implicit_link.h

LIB_CORE_b64_C = $(PROJ_SRC_DIR)\b64.c

########################################
# SRC_HEADERS

HEADERS_LIB	= \
 $(LIB_CORE_b64_H)\
 $(LIB_CORE_implicit_link_H)\
 \

HEADERS_MAPPING_CPP =\
 $(PROJ_INCLUDE_DIR)\b64\b64.hpp\
 \

########################################
# SRC_TESTS

SRC_TEST_C_1 = $(PROJ_TESTS_DIR)\c\test.c.1\test.c.1.c

########################################
# SRC_EXAMPLES

SRC_EXAMPLE_C_1 = $(PROJ_EXAMPLES_DIR)\c\example.c.1\example.c.1.c
SRC_EXAMPLE_C_2 = $(PROJ_EXAMPLES_DIR)\c\example.c.2\example.c.2.c

########################################
# SRC_SAMPLES

SRC_SAMPLE_C_1 = $(PROJ_SAMPLES_DIR)\c\sample.c.1\sample.c.1.c

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
	$(TARGET_TEST_C_1_ST_D) --unittest
	$(TARGET_TEST_C_1_ST_R) --unittest

test:		build.all test_

test.all:	test

test-all:	test.all	# backwards compatibility


usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean.libs.core:
	@-$(RM) $(TARGET_LIB_ST_D)
	@-$(RM) $(TARGET_LIB_UN_ST_D)
	@-$(RM) $(TARGET_LIB_ST_R)
	@-$(RM) $(TARGET_LIB_UN_ST_R)
	@-$(RM) $(OBJ_CORE_b64__ST_D)
	@-$(RM) $(OBJ_CORE_b64__ST_R)

clean.libs.com:	makefile

clean.libs.dotnet:	makefile

clean.libs:         clean.libs.core clean.libs.com clean.libs.dotnet

clean.test:
	@-$(RM) $(TARGET_TEST_C_1_ST_D)
	@-$(RM) $(TARGET_TEST_C_1_ST_R)
	@-$(RM) $(OBJ_TEST_C_1_ST_D)
	@-$(RM) $(OBJ_TEST_C_1_ST_R)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_R)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_R)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core


$(TARGET_LIB_UN_ST_D): $(TARGET_LIB_ST_D)
	@$(CP) $(TARGET_LIB_ST_D) $@

$(TARGET_LIB_ST_D): $(OBJS_CORE_ST_D) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_D_PM)

$(OBJ_CORE_b64__ST_D): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\b64.c


$(TARGET_LIB_UN_ST_R): $(TARGET_LIB_ST_R)
	@$(CP) $(TARGET_LIB_ST_R) $@

$(TARGET_LIB_ST_R): $(OBJS_CORE_ST_R) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_R_PM)

$(OBJ_CORE_b64__ST_R): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\b64.c


########################################
# test

# C test client

$(TARGET_TEST_C_1_ST_D):	$(OBJ_TEST_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_TEST_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_TEST_C_1_ST_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_ST_R):	$(OBJ_TEST_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_TEST_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_TEST_C_1_ST_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_TEST_C_1)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_ST_D):	$(OBJ_EXAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_EXAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_1_ST_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_D):	$(OBJ_EXAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_EXAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_2_ST_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_ST_R):	$(OBJ_EXAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_EXAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_1_ST_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_R):	$(OBJ_EXAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_EXAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_2_ST_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_EXAMPLE_C_2)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_ST_D):	$(OBJ_SAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -fe=$@ $(OBJ_SAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_C_1_ST_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_1_ST_R):	$(OBJ_SAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -fe=$@ $(OBJ_SAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_C_1_ST_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(SRC_SAMPLE_C_1)

################################################################################
