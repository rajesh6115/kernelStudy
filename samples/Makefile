obj-m += <objects.o>

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(pwd) modules
clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(pwd) clean
