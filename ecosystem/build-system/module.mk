# Reusable module targets: all, test, clean, install.

BUILD_SYSTEM_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
include $(BUILD_SYSTEM_DIR)/common.mk

MODULE_NAME ?= module
LIB_NAME ?= lib$(MODULE_NAME).a

SRCS ?= $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TEST_SRCS ?= $(wildcard $(TEST_DIR)/*.c)
TEST_BIN ?= $(BIN_DIR)/$(MODULE_NAME)-tests

INSTALL_LIB_DIR := $(DESTDIR)$(PREFIX)/lib
INSTALL_INCLUDE_DIR := $(DESTDIR)$(PREFIX)/include/$(MODULE_NAME)

.PHONY: all test clean install dirs

all: dirs $(BUILD_DIR)/$(LIB_NAME)

$(BUILD_DIR)/$(LIB_NAME): $(OBJS)
	$(AR) rcs $@ $^
	$(RANLIB) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

dirs:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

test: all
ifeq ($(strip $(TEST_SRCS)),)
	@echo "No tests found in $(TEST_DIR)"
else
	$(CC) $(CPPFLAGS) $(CFLAGS) $(TEST_SRCS) $(BUILD_DIR)/$(LIB_NAME) $(LDFLAGS) $(LDLIBS) -o $(TEST_BIN)
	$(TEST_BIN)
endif

clean:
	rm -rf $(BUILD_DIR)

install: all
	@mkdir -p $(INSTALL_LIB_DIR) $(INSTALL_INCLUDE_DIR)
	cp $(BUILD_DIR)/$(LIB_NAME) $(INSTALL_LIB_DIR)/$(LIB_NAME)
	if [ -d "$(INCLUDE_DIR)" ]; then cp -R $(INCLUDE_DIR)/. $(INSTALL_INCLUDE_DIR)/; fi
