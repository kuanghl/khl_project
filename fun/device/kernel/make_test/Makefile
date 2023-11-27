SHELL = /bin/bash

EXTRA_CFLAGS := -DSNPS_DRIVER
#EXTRA_CFLAGS += -D__LIBRPP_DEBUG__
#EXTRA_CFLAGS += -DDEBUG
EXTRA_CFLAGS += -w

EXTRA_CFLAGS += -v

TARGET_MODULE:=hello

ifneq ($(KERNELRELEASE),)
	$(TARGET_MODULE)-objs := hello_world.o 

	EXTRA_CFLAGS += -D'SRC="$(src)"'

ifneq ($(shell cd $(src) && git rev-parse HEAD),)
	EXTRA_CFLAGS += -D'GIT_STATUS="None"'
else
	EXTRA_CFLAGS += -D'GIT_STATUS="Yes"'
endif

	topdir := $(shell cd $(src) && pwd)
	EXTRA_CFLAGS += -I$(topdir)/include

	obj-m := $(TARGET_MODULE).o
else
	BUILDSYSTEM_DIR:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)

all:
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) modules
test:
	echo "test case"
clean:
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) clean
install:all
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) modules_install
endif