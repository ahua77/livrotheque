################################################################################
# File:     makefile
#
# Purpose:  Makefile for the b64 project, for the Visual C++ 8 (64-bit)
#           compiler, on Win64
#
# Created:  15th Feburary 2005
# Updated:  3rd August 2008
#
################################################################################


################################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # STLSOFT

################################################################################
# Symbols

# Identification

COMP_TAG          =   vc8_x64
PROJ_TAG          =   b64
PROJ_VER_MAJOR    =   1
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR)

CC                  =   cl
CPPC                =   cl
AR                  =   lib
LD                  =   link
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

CPPC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 -I"$(STLSOFT)\include"\
 \

3PTY_LIBS__MT_D = \
 \

3PTY_LIBS__DLL_D = \
 \

3PTY_LIBS__DLL_R = \
 \

3PTY_LIBS__MT_R = \
 \


LIB_PATHS =\
 \

LIBS_LEADER         =   

COMMON_LIB          =   

# #defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DB64_NO_IMPLICIT_LINK\
 \

COMMON_DEFS         =   -DWIN64 $(CMN_DEF_NO_IMPLICIT_LINK)

CC_DEFS             =   $(COMMON_DEFS)

CPPC_DEFS           =   $(COMMON_DEFS)

# Flags

CC_F_NOLOGO             =   -nologo
CC_F_COMPILE_ONLY       =   -c
CC_F_WARNING_MAX        =   -W4
CC_F_WARNING_ERR        =   -WX

CPPC_F_NOLOGO       =   -nologo
CPPC_F_COMPILE_ONLY =   -c
CPPC_F_WARNING_MAX  =   -W4 -wd4996
CPPC_F_WARNING_ERR  =   -WX
CPPC_F_EXCEPTIONS   =   -EHsc
CPPC_F_RTTI         =   -GR

CC_TOOL_FLAGS       =   

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CPPC_TOOL_FLAGS     =   

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

CC_ARGS_MT_D = -MTd -D_DEBUG -Zi -Fd$(TARGET_PDB_MT_D) $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_D = -MDd -D_DEBUG -Zi -Fd$(TARGET_PDB_DLL_D) $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_R = -MD -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_MT_R = -MT -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_MT_D = -MTd -D_DEBUG -Zi -Fd$(TARGET_PDB_MT_D) $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_DLL_D = -MDd -D_DEBUG -Zi -Fd$(TARGET_PDB_DLL_D) $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_DLL_R = -MD -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_MT_R = -MT -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

# archiver flags and arguments

AR_ARGS = -nologo

# linker flags and arguments

LD_F_NOLOGO = -nologo

LD_ARGS_MT_D =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_DLL_D = -debug -pdb:$(TARGET_PDB_DLL_D) $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_DLL_R =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_MT_R =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_MT_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).mt.debug.lib
TARGET_LIB_UN_MT_D = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.debug.lib
TARGET_PDB_MT_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).mt.debug.pdb
TARGET_LIB_DLL_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).dll.debug.lib
TARGET_LIB_UN_DLL_D = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).dll.debug.lib
TARGET_PDB_DLL_D = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).dll.debug.pdb
TARGET_LIB_DLL_R = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).dll.lib
TARGET_LIB_UN_DLL_R = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).dll.lib
TARGET_LIB_MT_R = $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).mt.lib
TARGET_LIB_UN_MT_R = $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.lib

TARGETS_LIBS =\
 $(TARGET_LIB_MT_D)\
 $(TARGET_LIB_UN_MT_D)\
 $(TARGET_PDB_MT_D)\
 $(TARGET_LIB_DLL_D)\
 $(TARGET_LIB_UN_DLL_D)\
 $(TARGET_PDB_DLL_D)\
 $(TARGET_LIB_DLL_R)\
 $(TARGET_LIB_UN_DLL_R)\
 $(TARGET_LIB_MT_R)\
 $(TARGET_LIB_UN_MT_R)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).mt.debug.exe
TARGET_TEST_CPP_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).mt.debug.exe
TARGET_TEST_C_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).dll.debug.exe
TARGET_TEST_CPP_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).dll.debug.exe
TARGET_TEST_C_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).dll.exe
TARGET_TEST_CPP_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).dll.exe
TARGET_TEST_C_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).mt.exe
TARGET_TEST_CPP_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).mt.exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_MT_D)\
 $(TARGET_TEST_C_1_DLL_D)\
 $(TARGET_TEST_C_1_DLL_R)\
 $(TARGET_TEST_C_1_MT_R)\
 $(TARGET_TEST_CPP_1_MT_D)\
 $(TARGET_TEST_CPP_1_DLL_D)\
 $(TARGET_TEST_CPP_1_DLL_R)\
 $(TARGET_TEST_CPP_1_MT_R)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_C_2_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_CPP_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_CPP_2_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).mt.debug.exe
TARGET_EXAMPLE_C_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_C_2_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_CPP_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_CPP_2_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).dll.debug.exe
TARGET_EXAMPLE_C_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_C_2_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_CPP_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_CPP_2_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).dll.exe
TARGET_EXAMPLE_C_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).mt.exe
TARGET_EXAMPLE_C_2_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).mt.exe
TARGET_EXAMPLE_CPP_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).mt.exe
TARGET_EXAMPLE_CPP_2_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).mt.exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_MT_D)\
 $(TARGET_EXAMPLE_C_2_MT_D)\
 $(TARGET_EXAMPLE_C_1_DLL_D)\
 $(TARGET_EXAMPLE_C_2_DLL_D)\
 $(TARGET_EXAMPLE_C_1_DLL_R)\
 $(TARGET_EXAMPLE_C_2_DLL_R)\
 $(TARGET_EXAMPLE_C_1_MT_R)\
 $(TARGET_EXAMPLE_C_2_MT_R)\
 $(TARGET_EXAMPLE_CPP_1_MT_D)\
 $(TARGET_EXAMPLE_CPP_2_MT_D)\
 $(TARGET_EXAMPLE_CPP_1_DLL_D)\
 $(TARGET_EXAMPLE_CPP_2_DLL_D)\
 $(TARGET_EXAMPLE_CPP_1_DLL_R)\
 $(TARGET_EXAMPLE_CPP_2_DLL_R)\
 $(TARGET_EXAMPLE_CPP_1_MT_R)\
 $(TARGET_EXAMPLE_CPP_2_MT_R)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).mt.debug.exe
TARGET_SAMPLE_CPP_1_MT_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.cpp.1.$(COMP_TAG).mt.debug.exe
TARGET_SAMPLE_C_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).dll.debug.exe
TARGET_SAMPLE_CPP_1_DLL_D = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.cpp.1.$(COMP_TAG).dll.debug.exe
TARGET_SAMPLE_C_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).dll.exe
TARGET_SAMPLE_CPP_1_DLL_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.cpp.1.$(COMP_TAG).dll.exe
TARGET_SAMPLE_C_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.c.1.$(COMP_TAG).mt.exe
TARGET_SAMPLE_CPP_1_MT_R = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample.cpp.1.$(COMP_TAG).mt.exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_MT_D)\
 $(TARGET_SAMPLE_C_1_DLL_D)\
 $(TARGET_SAMPLE_C_1_DLL_R)\
 $(TARGET_SAMPLE_C_1_MT_R)\
 $(TARGET_SAMPLE_CPP_1_MT_D)\
 $(TARGET_SAMPLE_CPP_1_DLL_D)\
 $(TARGET_SAMPLE_CPP_1_DLL_R)\
 $(TARGET_SAMPLE_CPP_1_MT_R)\
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

OBJ_CORE_b64__MT_D = $(PROJ_OBJ_DIR)\b64.mt.debug.obj

OBJS_CORE_MT_D = \
 $(OBJ_CORE_b64__MT_D)\
 \


OBJ_CORE_b64__DLL_D = $(PROJ_OBJ_DIR)\b64.dll.debug.obj

OBJS_CORE_DLL_D = \
 $(OBJ_CORE_b64__DLL_D)\
 \


OBJ_CORE_b64__DLL_R = $(PROJ_OBJ_DIR)\b64.dll.obj

OBJS_CORE_DLL_R = \
 $(OBJ_CORE_b64__DLL_R)\
 \


OBJ_CORE_b64__MT_R = $(PROJ_OBJ_DIR)\b64.mt.obj

OBJS_CORE_MT_R = \
 $(OBJ_CORE_b64__MT_R)\
 \


OBJS_CORE =\
 $(OBJS_CORE_MT_D)\
 $(OBJS_CORE_DLL_D)\
 $(OBJS_CORE_DLL_R)\
 $(OBJS_CORE_MT_R)\
 \

########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_C_1_MT_D = $(PROJ_OBJ_DIR)\test.c.1.mt.debug.obj
OBJ_TEST_CPP_1_MT_D = $(PROJ_OBJ_DIR)\test.cpp.1.mt.debug.obj
OBJ_TEST_C_1_DLL_D = $(PROJ_OBJ_DIR)\test.c.1.dll.debug.obj
OBJ_TEST_CPP_1_DLL_D = $(PROJ_OBJ_DIR)\test.cpp.1.dll.debug.obj
OBJ_TEST_C_1_DLL_R = $(PROJ_OBJ_DIR)\test.c.1.dll.obj
OBJ_TEST_CPP_1_DLL_R = $(PROJ_OBJ_DIR)\test.cpp.1.dll.obj
OBJ_TEST_C_1_MT_R = $(PROJ_OBJ_DIR)\test.c.1.mt.obj
OBJ_TEST_CPP_1_MT_R = $(PROJ_OBJ_DIR)\test.cpp.1.mt.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_MT_D)\
 $(OBJ_TEST_C_1_DLL_D)\
 $(OBJ_TEST_C_1_DLL_R)\
 $(OBJ_TEST_C_1_MT_R)\
 $(OBJ_TEST_CPP_1_MT_D)\
 $(OBJ_TEST_CPP_1_DLL_D)\
 $(OBJ_TEST_CPP_1_DLL_R)\
 $(OBJ_TEST_CPP_1_MT_R)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_MT_D = $(PROJ_OBJ_DIR)\example.c.1.mt.debug.obj
OBJ_EXAMPLE_C_2_MT_D = $(PROJ_OBJ_DIR)\example.c.2.mt.debug.obj
OBJ_EXAMPLE_CPP_1_MT_D = $(PROJ_OBJ_DIR)\example.cpp.1.mt.debug.obj
OBJ_EXAMPLE_CPP_2_MT_D = $(PROJ_OBJ_DIR)\example.cpp.2.mt.debug.obj
OBJ_EXAMPLE_C_1_DLL_D = $(PROJ_OBJ_DIR)\example.c.1.dll.debug.obj
OBJ_EXAMPLE_C_2_DLL_D = $(PROJ_OBJ_DIR)\example.c.2.dll.debug.obj
OBJ_EXAMPLE_CPP_1_DLL_D = $(PROJ_OBJ_DIR)\example.cpp.1.dll.debug.obj
OBJ_EXAMPLE_CPP_2_DLL_D = $(PROJ_OBJ_DIR)\example.cpp.2.dll.debug.obj
OBJ_EXAMPLE_C_1_DLL_R = $(PROJ_OBJ_DIR)\example.c.1.dll.obj
OBJ_EXAMPLE_C_2_DLL_R = $(PROJ_OBJ_DIR)\example.c.2.dll.obj
OBJ_EXAMPLE_CPP_1_DLL_R = $(PROJ_OBJ_DIR)\example.cpp.1.dll.obj
OBJ_EXAMPLE_CPP_2_DLL_R = $(PROJ_OBJ_DIR)\example.cpp.2.dll.obj
OBJ_EXAMPLE_C_1_MT_R = $(PROJ_OBJ_DIR)\example.c.1.mt.obj
OBJ_EXAMPLE_C_2_MT_R = $(PROJ_OBJ_DIR)\example.c.2.mt.obj
OBJ_EXAMPLE_CPP_1_MT_R = $(PROJ_OBJ_DIR)\example.cpp.1.mt.obj
OBJ_EXAMPLE_CPP_2_MT_R = $(PROJ_OBJ_DIR)\example.cpp.2.mt.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_MT_D)\
 $(OBJ_EXAMPLE_C_2_MT_D)\
 $(OBJ_EXAMPLE_C_1_DLL_D)\
 $(OBJ_EXAMPLE_C_2_DLL_D)\
 $(OBJ_EXAMPLE_C_1_DLL_R)\
 $(OBJ_EXAMPLE_C_2_DLL_R)\
 $(OBJ_EXAMPLE_C_1_MT_R)\
 $(OBJ_EXAMPLE_C_2_MT_R)\
 $(OBJ_EXAMPLE_CPP_1_MT_D)\
 $(OBJ_EXAMPLE_CPP_2_MT_D)\
 $(OBJ_EXAMPLE_CPP_1_DLL_D)\
 $(OBJ_EXAMPLE_CPP_2_DLL_D)\
 $(OBJ_EXAMPLE_CPP_1_DLL_R)\
 $(OBJ_EXAMPLE_CPP_2_DLL_R)\
 $(OBJ_EXAMPLE_CPP_1_MT_R)\
 $(OBJ_EXAMPLE_CPP_2_MT_R)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_MT_D = $(PROJ_OBJ_DIR)\sample.c.1.mt.debug.obj
OBJ_SAMPLE_CPP_1_MT_D = $(PROJ_OBJ_DIR)\sample.cpp.1.mt.debug.obj
OBJ_SAMPLE_C_1_DLL_D = $(PROJ_OBJ_DIR)\sample.c.1.dll.debug.obj
OBJ_SAMPLE_CPP_1_DLL_D = $(PROJ_OBJ_DIR)\sample.cpp.1.dll.debug.obj
OBJ_SAMPLE_C_1_DLL_R = $(PROJ_OBJ_DIR)\sample.c.1.dll.obj
OBJ_SAMPLE_CPP_1_DLL_R = $(PROJ_OBJ_DIR)\sample.cpp.1.dll.obj
OBJ_SAMPLE_C_1_MT_R = $(PROJ_OBJ_DIR)\sample.c.1.mt.obj
OBJ_SAMPLE_CPP_1_MT_R = $(PROJ_OBJ_DIR)\sample.cpp.1.mt.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_MT_D)\
 $(OBJ_SAMPLE_C_1_DLL_D)\
 $(OBJ_SAMPLE_C_1_DLL_R)\
 $(OBJ_SAMPLE_C_1_MT_R)\
 $(OBJ_SAMPLE_CPP_1_MT_D)\
 $(OBJ_SAMPLE_CPP_1_DLL_D)\
 $(OBJ_SAMPLE_CPP_1_DLL_R)\
 $(OBJ_SAMPLE_CPP_1_MT_R)\
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
SRC_TEST_CPP_1 = $(PROJ_TESTS_DIR)\cpp\test.cpp.1\test.cpp.1.cpp

########################################
# SRC_EXAMPLES

SRC_EXAMPLE_C_1 = $(PROJ_EXAMPLES_DIR)\c\example.c.1\example.c.1.c
SRC_EXAMPLE_C_2 = $(PROJ_EXAMPLES_DIR)\c\example.c.2\example.c.2.c
SRC_EXAMPLE_CPP_1 = $(PROJ_EXAMPLES_DIR)\cpp\example.cpp.1\example.cpp.1.cpp
SRC_EXAMPLE_CPP_2 = $(PROJ_EXAMPLES_DIR)\cpp\example.cpp.2\example.cpp.2.cpp

########################################
# SRC_SAMPLES

SRC_SAMPLE_C_1 = $(PROJ_SAMPLES_DIR)\c\sample.c.1\sample.c.1.c
SRC_SAMPLE_CPP_1 = $(PROJ_SAMPLES_DIR)\cpp\sample.cpp.1\sample.cpp.1.cpp

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
	$(TARGET_TEST_C_1_MT_D) --unittest
	$(TARGET_TEST_C_1_DLL_D) --unittest
	$(TARGET_TEST_C_1_DLL_R) --unittest
	$(TARGET_TEST_C_1_MT_R) --unittest
	$(TARGET_TEST_CPP_1_MT_D) --unittest
	$(TARGET_TEST_CPP_1_DLL_D) --unittest
	$(TARGET_TEST_CPP_1_DLL_R) --unittest
	$(TARGET_TEST_CPP_1_MT_R) --unittest

test:		build.all test_

test.all:	test

test-all:	test.all	# backwards compatibility


usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean.libs.core:
	@-$(RM) $(TARGET_LIB_MT_D)
	@-$(RM) $(TARGET_LIB_UN_MT_D)
	@-$(RM) $(TARGET_LIB_DLL_D)
	@-$(RM) $(TARGET_LIB_UN_DLL_D)
	@-$(RM) $(TARGET_LIB_DLL_R)
	@-$(RM) $(TARGET_LIB_UN_DLL_R)
	@-$(RM) $(TARGET_LIB_MT_R)
	@-$(RM) $(TARGET_LIB_UN_MT_R)
	@-$(RM) $(OBJ_CORE_b64__MT_D)
	@-$(RM) $(OBJ_CORE_b64__DLL_D)
	@-$(RM) $(OBJ_CORE_b64__DLL_R)
	@-$(RM) $(OBJ_CORE_b64__MT_R)

clean.libs.com:	makefile

clean.libs.dotnet:	makefile

clean.libs:         clean.libs.core clean.libs.com clean.libs.dotnet

clean.test:
	@-$(RM) $(TARGET_TEST_C_1_MT_D)
	@-$(RM) $(TARGET_TEST_C_1_DLL_D)
	@-$(RM) $(TARGET_TEST_C_1_DLL_R)
	@-$(RM) $(TARGET_TEST_C_1_MT_R)
	@-$(RM) $(TARGET_TEST_CPP_1_MT_D)
	@-$(RM) $(TARGET_TEST_CPP_1_DLL_D)
	@-$(RM) $(TARGET_TEST_CPP_1_DLL_R)
	@-$(RM) $(TARGET_TEST_CPP_1_MT_R)
	@-$(RM) $(OBJ_TEST_C_1_MT_D)
	@-$(RM) $(OBJ_TEST_C_1_DLL_D)
	@-$(RM) $(OBJ_TEST_C_1_DLL_R)
	@-$(RM) $(OBJ_TEST_C_1_MT_R)
	@-$(RM) $(OBJ_TEST_CPP_1_MT_D)
	@-$(RM) $(OBJ_TEST_CPP_1_DLL_D)
	@-$(RM) $(OBJ_TEST_CPP_1_DLL_R)
	@-$(RM) $(OBJ_TEST_CPP_1_MT_R)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_C_1_MT_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_MT_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_DLL_D)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_DLL_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_MT_R)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_MT_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_DLL_D)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_DLL_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_MT_R)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_MT_R)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_MT_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_DLL_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_DLL_R)
	@-$(RM) $(TARGET_SAMPLE_C_1_MT_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_MT_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_DLL_D)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_DLL_R)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_MT_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_MT_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_DLL_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_DLL_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_MT_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_MT_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_DLL_D)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_DLL_R)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_MT_R)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core

$(TARGET_PDB_MT_D):	$(TARGET_LIB_MT_D)

$(TARGET_LIB_UN_MT_D): $(TARGET_LIB_MT_D)
	@$(CP) $(TARGET_LIB_MT_D) $@

$(TARGET_LIB_MT_D): $(OBJS_CORE_MT_D) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_MT_D)

$(OBJ_CORE_b64__MT_D): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\b64.c

$(TARGET_PDB_DLL_D):	$(TARGET_LIB_DLL_D)

$(TARGET_LIB_UN_DLL_D): $(TARGET_LIB_DLL_D)
	@$(CP) $(TARGET_LIB_DLL_D) $@

$(TARGET_LIB_DLL_D): $(OBJS_CORE_DLL_D) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_DLL_D)

$(OBJ_CORE_b64__DLL_D): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\b64.c


$(TARGET_LIB_UN_DLL_R): $(TARGET_LIB_DLL_R)
	@$(CP) $(TARGET_LIB_DLL_R) $@

$(TARGET_LIB_DLL_R): $(OBJS_CORE_DLL_R) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_DLL_R)

$(OBJ_CORE_b64__DLL_R): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\b64.c


$(TARGET_LIB_UN_MT_R): $(TARGET_LIB_MT_R)
	@$(CP) $(TARGET_LIB_MT_R) $@

$(TARGET_LIB_MT_R): $(OBJS_CORE_MT_R) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_MT_R)

$(OBJ_CORE_b64__MT_R): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\b64.c


########################################
# test

# C test client

$(TARGET_TEST_C_1_MT_D):	$(OBJ_TEST_C_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_TEST_C_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_TEST_C_1_MT_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_DLL_D):	$(OBJ_TEST_C_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_TEST_C_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_TEST_C_1_DLL_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_DLL_R):	$(OBJ_TEST_C_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_TEST_C_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_TEST_C_1_DLL_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_MT_R):	$(OBJ_TEST_C_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_TEST_C_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_TEST_C_1_MT_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_TEST_C_1)

# C++ test client

$(TARGET_TEST_CPP_1_MT_D):	$(OBJ_TEST_CPP_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_TEST_CPP_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_TEST_CPP_1_MT_D):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_1_DLL_D):	$(OBJ_TEST_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_TEST_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_TEST_CPP_1_DLL_D):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_1_DLL_R):	$(OBJ_TEST_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_TEST_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_TEST_CPP_1_DLL_R):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_1_MT_R):	$(OBJ_TEST_CPP_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_TEST_CPP_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_TEST_CPP_1_MT_R):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_TEST_CPP_1)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_MT_D):	$(OBJ_EXAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_C_1_MT_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_MT_D):	$(OBJ_EXAMPLE_C_2_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_C_2_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_C_2_MT_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_DLL_D):	$(OBJ_EXAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_C_1_DLL_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_DLL_D):	$(OBJ_EXAMPLE_C_2_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_C_2_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_C_2_DLL_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_DLL_R):	$(OBJ_EXAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_C_1_DLL_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_DLL_R):	$(OBJ_EXAMPLE_C_2_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_C_2_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_C_2_DLL_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_1_MT_R):	$(OBJ_EXAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_C_1_MT_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_MT_R):	$(OBJ_EXAMPLE_C_2_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_C_2_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_C_2_MT_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_C_2)

# C++ example client

$(TARGET_EXAMPLE_CPP_1_MT_D):	$(OBJ_EXAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_CPP_1_MT_D):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_MT_D):	$(OBJ_EXAMPLE_CPP_2_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_EXAMPLE_CPP_2_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_EXAMPLE_CPP_2_MT_D):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_DLL_D):	$(OBJ_EXAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_CPP_1_DLL_D):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_DLL_D):	$(OBJ_EXAMPLE_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_EXAMPLE_CPP_2_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_EXAMPLE_CPP_2_DLL_D):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_DLL_R):	$(OBJ_EXAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_CPP_1_DLL_R):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_DLL_R):	$(OBJ_EXAMPLE_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_EXAMPLE_CPP_2_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_EXAMPLE_CPP_2_DLL_R):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_1_MT_R):	$(OBJ_EXAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_CPP_1_MT_R):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_MT_R):	$(OBJ_EXAMPLE_CPP_2_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_EXAMPLE_CPP_2_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_EXAMPLE_CPP_2_MT_R):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_EXAMPLE_CPP_2)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_MT_D):	$(OBJ_SAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_SAMPLE_C_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_SAMPLE_C_1_MT_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_1_DLL_D):	$(OBJ_SAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_SAMPLE_C_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_SAMPLE_C_1_DLL_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_1_DLL_R):	$(OBJ_SAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_SAMPLE_C_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_SAMPLE_C_1_DLL_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_1_MT_R):	$(OBJ_SAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_SAMPLE_C_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_SAMPLE_C_1_MT_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(SRC_SAMPLE_C_1)

# C++ sample client

$(TARGET_SAMPLE_CPP_1_MT_D):	$(OBJ_SAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) makefile
	$(LD) $(LD_ARGS_MT_D) -out:$@ $(OBJ_SAMPLE_CPP_1_MT_D) $(TARGET_LIB_MT_D) $(3PTY_LIBS__MT_D)

$(OBJ_SAMPLE_CPP_1_MT_D):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_1_DLL_D):	$(OBJ_SAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) makefile
	$(LD) $(LD_ARGS_DLL_D) -out:$@ $(OBJ_SAMPLE_CPP_1_DLL_D) $(TARGET_LIB_DLL_D) $(3PTY_LIBS__DLL_D)

$(OBJ_SAMPLE_CPP_1_DLL_D):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_1_DLL_R):	$(OBJ_SAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) makefile
	$(LD) $(LD_ARGS_DLL_R) -out:$@ $(OBJ_SAMPLE_CPP_1_DLL_R) $(TARGET_LIB_DLL_R) $(3PTY_LIBS__DLL_R)

$(OBJ_SAMPLE_CPP_1_DLL_R):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_1_MT_R):	$(OBJ_SAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) makefile
	$(LD) $(LD_ARGS_MT_R) -out:$@ $(OBJ_SAMPLE_CPP_1_MT_R) $(TARGET_LIB_MT_R) $(3PTY_LIBS__MT_R)

$(OBJ_SAMPLE_CPP_1_MT_R):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(SRC_SAMPLE_CPP_1)

################################################################################
