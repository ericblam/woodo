woodo: woodo.h woodo.c
	gcc -w -o woodo woodo.c

install: woodo
	mv woodo /usr/local/bin
	cp woodo.1 woodo.6
	gzip woodo.6
	mv woodo.6.gz /usr/share/man/man6/

clean:
	rm woodo
