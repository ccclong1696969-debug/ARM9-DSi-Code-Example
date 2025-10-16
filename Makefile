#---------------------------------------------------------------------------------
# A simple Makefile for a Nintendo DSi homebrew application.
#---------------------------------------------------------------------------------

# The name of the target binary (e.g., HelloDSi.nds)
TARGET HelloDSi.nds:= $(notdir $(CURDIR))

# The NDS icon for your application. It must be a 32x32 pixel, 256-color BMP.
# You can leave this out, but your app will have a default icon.
ICON icon.bmp:= icon.bmp

# The build directory where object files will be stored.
BUILD buildoutput:= build

# The source directory.
SOURCE sources:= source

# List of your C source files.
SOURCES main.c:= $(wildcard $(SOURCE)/*.c)

# List of your C++ source files.
SOURCES_CPP := $(wildcard $(SOURCE)/*.cpp)

# List of your ARM assembly source files.
SOURCES_S   := $(wildcard $(SOURCE)/*.s)

#---------------------------------------------------------------------------------
# DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
# Check if devkitPro is installed
ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitpro")
endif

# Include the main build rules from libnds
include $(DEVKITPRO)/libnds/build_tools/make_rules
