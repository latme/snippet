
CFLAGS += -I$(CURDIR)/include
CFLAGS += -MD -MP -MF $*.d
#CFLAGS += -MMD -MP -MF $*.d	# do not include standard header file (/usr/include)


TARGET := latbox
SRCS   := main.c
SRCS   += mem/common.c mem/cmd_mr.c mem/cmd_mw.c mem/cmd_ior.c mem/cmd_iow.c
OBJS   := $(SRCS:.c=.o)
DEPS   := $(SRCS:.c=.d)



$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^


-include $(DEPS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<


install :
	@[ -d /usr/local/sbin ] || mkdir -p /usr/local/sbin
	@[ -e /usr/local/sbin/md ] || ln -s /usr/local/sbin/$(TARGET) /usr/local/sbin/md
	@[ -e /usr/local/sbin/mm ] || ln -s /usr/local/sbin/$(TARGET) /usr/local/sbin/mm
	cp -pf $(TARGET) /usr/local/sbin


.PHONY : clean
clean :
	rm -f $(TARGET) $(OBJS) $(DEPS)

