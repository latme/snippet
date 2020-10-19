# Compile toolchain
AR := ar
AS := as
CC := gcc
LD := ld
OBJDUMP := objdump
OBJCOPY := objcopy

CFLAGS  := -O0
CFLAGS  += -Iinclude
AFLAGS  :=
LDFLAGS :=


%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o : %.S
	$(AS) $(AFLAGS) -o $@ $<
