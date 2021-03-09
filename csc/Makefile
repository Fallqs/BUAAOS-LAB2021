all: ./code/fibo.c ./code/main.c
	gcc -I ./include -c ./code/fibo.c
	gcc -I ./include  -c ./code/main.c
	mv main.o ./code
	mv fibo.o ./code
	gcc -I ./include ./code/main.o ./code/fibo.o -o fibo
	
clean: 
	rm ./code/*.o
