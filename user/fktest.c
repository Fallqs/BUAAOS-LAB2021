#include "lib.h"


void umain()
{
	int a = 0;
	int id = 0;

	if ((id = fork()) == 0) {
		if ((id = fork()) == 0) {
			a += 3;

			for (;;) {
				writef("\t\tthis is CHILD=%d :a:%d\n", id, a);
			}
		}

		a += 2;

		for (;;) {
			writef("\tthis is child=%d :a:%d\n", id, a);
		}
	}

	a++;

	for (;;) {
		writef("this is father=%d : a:%d\n", id, a);
	}
}
