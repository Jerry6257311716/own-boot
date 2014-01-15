DRIVERS-y :=
DRIVERS-y += head.o
DRIVERS-y += init.o
DRIVERS-y += main.o
DRIVERS-y += nand.o

objs := $(DRIVERS-y)

CROSSTOOLDIR 	:= /usr/local/arm/4.3.2
CROSS_COMPILE   = $(CROSSTOOLDIR)/bin/arm-linux-
CC          	= $(CROSS_COMPILE)gcc
LD          	= $(CROSS_COMPILE)ld
OBJCOPY     	= $(CROSS_COMPILE)objcopy
OBJDUMP     	= $(CROSS_COMPILE)objdump
NM		     	= $(CROSS_COMPILE)nm

LINKFLAGS 	= 	-Town-boot.lds -static

own-boot.bin : $(objs)
	$(LD) -v $(LINKFLAGS) -o own-boot_elf $(objs) 
	$(OBJCOPY) -O binary -S own-boot_elf $@
	$(OBJDUMP) -D -m arm  own-boot_elf > own-boot.dis
	$(NM) -v -l own-boot_elf > own-boot.map
	./checksum.sh own-boot.bin
	
%.o:%.c
	$(CC) -Wall -c -O2 -o $@ $< 
	
clean: 
	rm -f checksum
	find -name '*.o' | xargs rm -f
	rm -f own-boot.bin own-boot_elf 
	rm -f own-boot.dis own-boot.map	
	
