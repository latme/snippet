include Makefile.mk


TARGET := snippet.elf
OBJS   := main.o


$(TARGET) : $(OBJS)
#	$(LD) $(LDFLAGS) $(OBJS) -o $@
	$(CC) $(LDFLAGS) $(OBJS) -o $@



.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJS)

