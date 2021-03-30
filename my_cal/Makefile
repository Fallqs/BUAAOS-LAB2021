INCLUDES := -I../include
all: my_dr my_ca
my_dr: my_driver.o
my_ca:  my_cal.o

%.o: %.S
	$(CC) $(CFLAGS) $(INCLUDES) -c $< 

%.o: %.c
	$(CC) $(DEFS) $(CFLAGS) $(INCLUDES) -c $<

.PHONY: clean

clean:
	rm -rf *~ *.o


include ../include.mk

