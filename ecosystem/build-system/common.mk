# Shared defaults for all ecosystem modules.

CC ?= cc
AR ?= ar
RANLIB ?= ranlib

BUILD_MODE ?= debug
PREFIX ?= $(HOME)/.local
DESTDIR ?=

SRC_DIR ?= src
INCLUDE_DIR ?= include
TEST_DIR ?= tests
BUILD_DIR ?= build
OBJ_DIR ?= $(BUILD_DIR)/obj
BIN_DIR ?= $(BUILD_DIR)/bin

CSTD ?= c11
CFLAGS_BASE ?= -std=$(CSTD) -Wall -Wextra -Werror
CFLAGS_DEBUG ?= -O0 -g3 -DDEBUG
CFLAGS_RELEASE ?= -O2 -DNDEBUG
CPPFLAGS ?= -I$(INCLUDE_DIR)
LDFLAGS ?=
LDLIBS ?=

ifeq ($(BUILD_MODE),debug)
  CFLAGS_MODE := $(CFLAGS_DEBUG)
else ifeq ($(BUILD_MODE),release)
  CFLAGS_MODE := $(CFLAGS_RELEASE)
else
  $(error BUILD_MODE must be 'debug' or 'release' (got '$(BUILD_MODE)'))
endif

CFLAGS ?= $(CFLAGS_BASE) $(CFLAGS_MODE)
