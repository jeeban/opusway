c: main.c
	if [ -e main ]; then rm main; fi;
	gcc main.c -o main -Wall -Wextra `pkg-config --libs --cflags gtk+-2.0` 1>compile-result 2>&1
r:c
	clear
	/usr/bin/time -v ./main
run:
	clear
	./main
	
