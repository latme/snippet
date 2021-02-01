include Makefile.mk

TOPDIR=$(CURDIR)
export TOPDIR

CFLAGS += -I$(TOPDIR)/include
export CFLAGS


all :


TARGET := snippet.elf
OBJS   := main.o


$(TARGET) : $(OBJS)
#	$(LD) $(LDFLAGS) $(OBJS) -o $@
	$(CC) $(LDFLAGS) $(OBJS) -o $@


box ::
	make -C box

help ::
	@echo 'make box      # build latbox target that conaint a servial comand set.'

.PHONY : clean
clean :
	make -C box clean
	rm -rf $(TARGET) $(OBJS)

