
CFLAGS += -I$(CURDIR)/include


TARGET := latbox
OBJS := main.o
OBJS += mem/common.o mem/cmd_mr.o mem/cmd_mw.o





$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^


%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<


install :
	@[ -d /usr/local/sbin ] || mkdir -p /usr/local/sbin
	@[ -e /usr/local/sbin/md ] || ln -s /usr/local/sbin/$(TARGET) /usr/local/sbin/md
	@[ -e /usr/local/sbin/mm ] || ln -s /usr/local/sbin/$(TARGET) /usr/local/sbin/mm
	cp -pf $(TARGET) /usr/local/sbin


.PHONY : clean
clean :
	rm -f $(TARGET) $(OBJS)

