all:
		gcc -o morse morse.c -Wall -ansi -pedantic -lwiringPi

clean:
		@rm -rf morse
