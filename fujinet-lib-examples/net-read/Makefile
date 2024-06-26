TARGETS := atari apple2
PROGRAM := netread

# set to 1 to make application auto start on boot of disk
AUTOSTART := 1

# See later for setting server IP address
# REST_SERVER_ADDRESS = \"$(shell hostname)\"
REST_SERVER_PORT = \"8080\"

include ../fnlib_platforms.mk

FUJINET_LIB_VERSION := 3.0.3
FUJINET_LIB := ../_libs
FUJINET_LIB_VERSION_DIR = $(FUJINET_LIB)/$(FUJINET_LIB_VERSION)-$(CURRENT_PLATFORM)
FUJINET_LIB_PATH = $(FUJINET_LIB_VERSION_DIR)/fujinet-$(CURRENT_PLATFORM)-$(FUJINET_LIB_VERSION).lib

APPLE_TOOLS_DIR := ../../apple-tools

CC := cl65

# Used as global "include" dir for macros etc.
COMMON_INC_DIR := ../_include

SRCDIR := src
BUILD_DIR := build
OBJDIR := obj

# This allows src to be nested withing sub-directories.
rwildcard=$(wildcard $(1)$(2))$(foreach d,$(wildcard $1*), $(call rwildcard,$d/,$2))

ifeq ($(shell echo),)
  MKDIR = mkdir -p $1
  RMDIR = rmdir $1
  RMFILES = $(RM) $1
else
  MKDIR = mkdir $(subst /,\,$1)
  RMDIR = rmdir $(subst /,\,$1)
  RMFILES = $(if $1,del /f $(subst /,\,$1))
endif
COMMA := ,
SPACE := $(N/A) $(N/A)
define NEWLINE


endef
# Note: Do not remove any of the two empty lines above !

############################################################################
# START OF MAIN LOOP IF THERE ARE MULTIPLE TARGETS
TARGETLIST := $(subst $(COMMA),$(SPACE),$(TARGETS))

ifeq ($(words $(TARGETLIST)),1)
CURRENT_TARGET := $(TARGETLIST)

FUJINET_LIB_DOWNLOAD_URL = https://github.com/FujiNetWIFI/fujinet-lib/releases/download/v$(FUJINET_LIB_VERSION)/fujinet-lib-$(CURRENT_PLATFORM)-$(FUJINET_LIB_VERSION).zip
FUJINET_LIB_DOWNLOAD_FILE = $(FUJINET_LIB)/fujinet-lib-$(CURRENT_PLATFORM)-$(FUJINET_LIB_VERSION).zip

ifeq '$(findstring ;,$(PATH))' ';'
    detected_OS := Windows
else
    detected_OS := $(shell uname 2>/dev/null || echo Unknown)
    detected_OS := $(patsubst CYGWIN%,Cygwin,$(detected_OS))
    detected_OS := $(patsubst MSYS%,MSYS,$(detected_OS))
    detected_OS := $(patsubst MINGW%,MSYS,$(detected_OS))
endif

# MSYS2 environment hack for extra slash (XS) needed in cmd line args
XS := ""
ifeq ($(detected_OS),$(filter $(detected_OS),MSYS MINGW))
	XS := /
endif

ALTIRRA ?= $(ALTIRRA_HOME)/Altirra64.exe \
  $(XS)/portable $(XS)/portablealt:altirra-debug.ini \

#   $(XS)/debug \
#   $(XS)/debugcmd: ".loadsym build\$(PROGRAM).$(CURRENT_TARGET).lbl" \
#   $(XS)/debugcmd: "bp _debug" \

atari_EMUCMD := $(ALTIRRA)

####################################
# REST_SERVER_ADDRESS
####################################
# If REST_SERVER_ADDRESS is already set on command line, these do nothing, otherwise they will work out the local IP address, ignoring 172 range which is WSL on Windows.
ifeq ($(detected_OS),Linux)
  REST_SERVER_ADDRESS = \"$(shell ip -4 addr show scope global | grep -oP '(?<=inet\s)\d+(\.\d+){3}')\"
else ifeq ($(detected_OS),$(filter $(detected_OS),MSYS MINGW Cygwin Windows))
  REST_SERVER_ADDRESS = \"$(shell ipconfig | grep -oP 'IPv4.*:\s*\K[\d.]+' | grep -v '^172\.')\"
endif

PREEMUCMD :=
POSTEMUCMD :=

ifeq ($(EMUCMD),)
  EMUCMD = $($(TARGETLIST)_EMUCMD)
endif

PROGRAM_TGT := $(PROGRAM).$(CURRENT_TARGET)

# Add all root level src dirs, if you use rwildcard, it will recursively search down dirs
SOURCES := $(call rwildcard,$(SRCDIR)/,*.s)
SOURCES += $(call rwildcard,$(SRCDIR)/,*.c)

# remove trailing and leading spaces.
SOURCES := $(strip $(SOURCES))

OBJ1 := $(SOURCES:.c=.o)
OBJECTS := $(OBJ1:.s=.o)
# change from src/ -> obj/<target>/ for generating compiled files into obj dir
OBJECTS := $(OBJECTS:$(SRCDIR)/%=$(OBJDIR)/$(CURRENT_TARGET)/%)

DEPENDS := $(OBJECTS:.o=.d)
STATEFILE := Makefile.options

LIBS += $(FUJINET_LIB_PATH)
ASFLAGS += --asm-include-dir $(FUJINET_LIB_VERSION_DIR)
CFLAGS += --include-dir $(FUJINET_LIB_VERSION_DIR)

# add common/inc
ASFLAGS += --asm-include-dir $(COMMON_INC_DIR)
CFLAGS += --include-dir $(COMMON_INC_DIR)

# Add src and src/include dirs as include locations to cater for H files with src, or in subdir
ASFLAGS += --asm-include-dir $(SRCDIR) --asm-include-dir $(SRCDIR)/include
CFLAGS += --include-dir $(SRCDIR) --include-dir $(SRCDIR)/include

CFLAGS += -DREST_SERVER_ADDRESS=$(REST_SERVER_ADDRESS) -DREST_SERVER_PORT=$(REST_SERVER_PORT)
ASFLAGS += -DREST_SERVER_ADDRESS=$(REST_SERVER_ADDRESS) -DREST_SERVER_PORT=$(REST_SERVER_PORT)
LDFLAGS += -DREST_SERVER_ADDRESS=$(REST_SERVER_ADDRESS) -DREST_SERVER_PORT=$(REST_SERVER_PORT)

# Fix for graphics calls on Atari
ifeq ($(CURRENT_PLATFORM),atari)
# LDFLAGS += -Wl -D__RESERVED_MEMORY__=0x1
endif

# Fix for loading location for Atari to be above SDX
ifeq ($(CURRENT_PLATFORM),atari)
LDFLAGS += --start-addr 0x2D00
endif

# Autoboot detection
ifeq ($(CURRENT_PLATFORM),apple2)
ifeq ($(AUTOSTART),1)
AUTOBOOT := -a
else
AUTOBOOT :=
endif
endif

# Split out OBJ files for each target separately.
TARGETOBJDIR := $(OBJDIR)/$(CURRENT_TARGET)

.SUFFIXES:
.PHONY: all clean dist get_fujinet_lib $(PROGRAM).$(CURRENT_TARGET)

all: get_fujinet_lib $(PROGRAM_TGT)

-include $(DEPENDS)
-include $(STATEFILE)

define _listing_
  CFLAGS += --listing $$(@:.o=.lst)
  ASFLAGS += --listing $$(@:.o=.lst)
endef

define _mapfile_
  LDFLAGS += --mapfile $$@.map
endef

define _labelfile_
  LDFLAGS += -Ln $$@.lbl
endef

ifeq ($(origin _OPTIONS_),file)
OPTIONS = $(_OPTIONS_)
$(eval $(OBJECTS): $(STATEFILE))
endif

# Transform the abstract OPTIONS to the actual cc65 options.
$(foreach o,$(subst $(COMMA),$(SPACE),$(OPTIONS)),$(eval $(_$o_)))

get_fujinet_lib:
	@if [ ! -f "$(FUJINET_LIB_DOWNLOAD_FILE)" ]; then \
		if [ -d "$(FUJINET_LIB_VERSION_DIR)" ]; then \
		  echo "A directory already exists with version $(FUJINET_LIB_VERSION) - please remove it first"; \
			exit 1; \
		fi; \
		HTTPSTATUS=$$(curl -Is $(FUJINET_LIB_DOWNLOAD_URL) | head -n 1 | awk '{print $$2}'); \
		if [ "$${HTTPSTATUS}" == "404" ]; then \
			echo "ERROR: Unable to find file $(FUJINET_LIB_DOWNLOAD_URL)"; \
			exit 1; \
		fi; \
		echo "Downloading fujinet-lib for $(TARGETLIST) version $(FUJINET_LIB_VERSION) from $(FUJINET_LIB_DOWNLOAD_URL)"; \
		mkdir -p $(FUJINET_LIB); \
		curl -L $(FUJINET_LIB_DOWNLOAD_URL) -o $(FUJINET_LIB_DOWNLOAD_FILE); \
		echo "Unzipping to $(FUJINET_LIB)"; \
		unzip -o $(FUJINET_LIB_DOWNLOAD_FILE) -d $(FUJINET_LIB_VERSION_DIR); \
		echo "Unzip complete."; \
	fi

$(OBJDIR):
	$(call MKDIR,$@)

$(TARGETOBJDIR):
	$(call MKDIR,$@)

$(BUILD_DIR):
	$(call MKDIR,$@)

SRC_INC_DIRS := \
	$(sort $(dir $(wildcard $(SRCDIR)/*)))

# $(info $$SOURCES = $(SOURCES))
# $(info $$OBJECTS = $(OBJECTS))
# $(info $$SRC_INC_DIRS = $(SRC_INC_DIRS))
# $(info $$ASFLAGS = $(ASFLAGS))
# $(info $$TARGETOBJDIR = $(TARGETOBJDIR))
# $(info $$CURRENT_TARGET = $(CURRENT_TARGET))
# $(info $$PROGRAM = $(PROGRAM))
# $(info $$PROGRAM_TGT = $(PROGRAM_TGT))

vpath %.c $(SRC_INC_DIRS)

$(TARGETOBJDIR)/%.o: %.c | $(TARGETOBJDIR)
	@$(call MKDIR,$(dir $@))
	$(CC) -t $(CURRENT_TARGET) -c --create-dep $(@:.o=.d) $(CFLAGS) -o $@ $<

vpath %.s $(SRC_INC_DIRS)

$(TARGETOBJDIR)/%.o: %.s | $(TARGETOBJDIR)
	@$(call MKDIR,$(dir $@))
	$(CC) -t $(CURRENT_TARGET) -c --create-dep $(@:.o=.d) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/$(PROGRAM_TGT): $(OBJECTS) $(LIBS) | $(BUILD_DIR)
	$(CC) -t $(CURRENT_TARGET) $(LDFLAGS) -o $@ $(patsubst %.cfg,-C %.cfg,$^)

$(PROGRAM_TGT): $(BUILD_DIR)/$(PROGRAM_TGT) | $(BUILD_DIR)

test: $(PROGRAM_TGT)
	$(PREEMUCMD)
	$(EMUCMD) $(BUILD_DIR)\\$<
	$(POSTEMUCMD)

clean:
	$(call RMFILES,$(OBJECTS))
	$(call RMFILES,$(DEPENDS))
	$(call RMFILES,$(TARGETOBJDIR)/*.lst)
	$(call RMFILES,$(BUILD_DIR)/*.lbl)
	$(call RMFILES,$(BUILD_DIR)/*.map)
	$(call RMFILES,$(BUILD_DIR)/$(PROGRAM_TGT))

dist: $(PROGRAM_TGT)
	$(call MKDIR,dist/)
	$(call RMFILES,dist/$(PROGRAM_TGT)*)
	cp build/$(PROGRAM_TGT) dist/$(PROGRAM_TGT).com

atr: dist
	$(call MKDIR,dist/atr)
	cp dist/$(PROGRAM_TGT).com dist/atr/$(PROGRAM).com
	$(call RMFILES,dist/*.atr)
	dir2atr -S dist/$(PROGRAM).atr dist/atr

po: dist
	$(call RMFILES,dist/$(APP_NAME)*.po)
	cp dist/$(PROGRAM_TGT).com dist/$(PROGRAM)
	$(APPLE_TOOLS_DIR)/mk-bitsy.sh dist/$(PROGRAM).po TEST_$(PROGRAM)
	$(APPLE_TOOLS_DIR)/add-file.sh ${AUTOBOOT} dist/$(PROGRAM).po dist/$(PROGRAM) $(PROGRAM)

gendebug: $(PROGRAM_TGT)
	@echo "Generating debug.scr script for AppleWin"
	@echo 'echo "Loading symbols"' > build/debug.scr
	@awk '{printf("sym %s = %s\n", substr($$3, 2), $$2)}' < build/$(PROGRAM_TGT).lbl >> build/debug.scr
	@echo 'bpx _main' >> build/debug.scr
	@echo 'bpx _debug' >> build/debug.scr
	@echo 'bpx _network_open' >> build/debug.scr
	@echo 'bpx _sp_init' >> build/debug.scr

############################################################################
else # $(words $(TARGETLIST)),1

all test clean:
	$(foreach t,$(TARGETLIST),$(MAKE) TARGETS=$t --no-print-directory clean all dist$(NEWLINE))

############################################################################
endif # $(words $(TARGETLIST)),1
