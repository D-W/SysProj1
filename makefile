tunes: tunez.c
	clang tunez.c -o tunes

run: tunes
	./tunes

clean:
	rm *~
