woodo: woodo.h woodo.c
	gcc -w -o woodo woodo.c

install: woodo
	cp woodo /usr/bin

clean:
	rm woodo
