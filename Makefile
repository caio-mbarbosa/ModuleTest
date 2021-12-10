obj-m = moduleTest.o #Nome do arquivo que voce está compilando
CC = gcc


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
