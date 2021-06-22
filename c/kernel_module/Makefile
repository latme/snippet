obj-m := mod_latme.o


all ::
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean ::
	rm -f *.ko *.o  .*.cmd .*.d  *.mod *.mod.c  modules.order Module.symvers

