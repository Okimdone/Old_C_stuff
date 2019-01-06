all: prog1 prog2 prog3

prog1: prog1.c
	gcc prog1.c -o prog1  -std=c99 -Wall

prog2: prog2.c
	gcc prog1.c -o prog2 -std=c99 -Wall

prog3: prog3.c
	gcc prog1.c -o prog2 -std=c99 -Wall -pthread

gdb_p1: prog1.c
	gcc prog1.c -o prog1  -std=c99 -Wall -g

gdb_p2: prog2.c
	gcc prog1.c -o prog1  -std=c99 -Wall -g

gdb_p3: prog3.c
	gcc prog1.c -o prog2 -std=c99 -Wall -pthread -g

clean:
	rm -f *.o prog1 prog2 prog3