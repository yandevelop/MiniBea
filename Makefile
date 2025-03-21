TARGET := iphone:clang:18.0:14.0
INSTALL_TARGET_PROCESSES = BeReal
ARCHS = arm64 arm64e

THEOS_DEVICE_IP=192.168.102.61
THEOS_PACKAGE_SCHEME=rootless

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = MiniBea

$(TWEAK_NAME)_FILES = Tweak/Tweak.x $(shell find Utilities -name '*.m') $(shell find BeFake -name '*.m')
$(TWEAK_NAME)_CFLAGS = -fobjc-arc

ifeq ($(JAILED), 1)
$(TWEAK_NAME)_FILES += fishhook/fishhook.c SideloadFix/SideloadFix.xm
$(TWEAK_NAME)_CFLAGS += -D JAILED=1
endif

include $(THEOS_MAKE_PATH)/tweak.mk
