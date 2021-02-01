# Compile toolchain
AR := ar
AS := as
CC := gcc
LD := ld
OBJDUMP := objdump
OBJCOPY := objcopy
export AR AS CC LD OBJDUMP OBJCOPY

CFLAGS  := -O0
CFLAGS  += -Iinclude
AFLAGS  :=
LDFLAGS :=
export CFLAGS AFLAGS LDFLAGS


%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o : %.S
	$(AS) $(AFLAGS) -o $@ $<

