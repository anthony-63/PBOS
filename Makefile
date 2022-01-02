ifneq (,)
This makefile requires GNU Make.
endif

override KERNEL := bin/pbos.elf
override ISO 	:= bin/pbos.iso

ifeq ($(origin CC), default)
CC := cc
endif

ifeq ($(origin LD), default)
LD := ld
endif

CFLAGS ?= -Wall -Wextra -O2 -pipe -Wno-attributes -Wno-pointer-to-int-cast

LDFLAGS ?=

override INTERNALCFLAGS :=   \
	-Iinclude/           \
	-Isrc/				 \
	-std=gnu11           \
	-ffreestanding       \
	-fno-stack-protector \
	-fno-pic             \
	-mabi=sysv           \
	-mno-80387           \
	-mno-mmx             \
	-mno-3dnow           \
	-mno-sse             \
	-mno-sse2            \
	-mno-red-zone        \
	-mcmodel=kernel      \
	-MMD				 \
	-masm=intel
override INTERNALLDFLAGS :=    \
	-Tlinker/linker.ld            \
	-nostdlib              \
	-zmax-page-size=0x1000 \
	-static

override CFILES := $(shell find ./src -type f -name '*.c')


override OBJ := $(CFILES:.c=.o)
override HEADER_DEPS := $(CFILES:.c=.d)

.PHONY: all
all: $(KERNEL)


$(KERNEL): $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) $(INTERNALLDFLAGS) -o $@
	make clean_files

-include $(HEADER_DEPS)
%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(KERNEL)

.PHONY: clean_files
CLEANFILES := $(shell find ./ -type f -name '*.d')
CLEANFILES += $(shell find ./ -type f -name '*.o')
clean_files:
	rm -rf $(CLEANFILES)

.PHONY: img
img:
	make -C limine
	mkdir -p iso_root
	cp -v $(KERNEL) limine.cfg limine/limine.sys \
      limine/limine-cd.bin limine/limine-eltorito-efi.bin iso_root/
	xorriso -as mkisofs -b limine-cd.bin \
        -no-emul-boot -boot-load-size 4 -boot-info-table \
        --efi-boot limine-eltorito-efi.bin \
        -efi-boot-part --efi-boot-image --protective-msdos-label \
        iso_root -o $(ISO)
	cp limine/limine.sys bin/
	./limine/limine-install $(ISO)
	rm bin/limine.sys

.PHONY: run
run:
	qemu-system-x86_64 -m 512M -cdrom $(ISO) -d int -D logfile.txt -M smm=off -no-reboot

rall:
	make
	make img
	make run
