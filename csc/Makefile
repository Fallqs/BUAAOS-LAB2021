CC=gcc
CFLAGS=-I./include

mfibo: ./code/fibo.o ./code/main.o
	@cd ./code && make
	$(CC) $(CFLAGS) -o fibo ./code/fibo.o ./code/main.o 
	#gcc -I ./include ./code/main.o ./code/fibo.o -o fibo
	
.PHONY:clean
clean: 
	@cd ./code && make clean
	#rm ./code/main.o
	rm fibo
