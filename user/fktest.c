#include "lib.h"


void umain()
{
	int a = 0;
	int id = 0;

	if ((id = tfork()) == 0) {
		if ((id = tfork()) == 0) {
			a += 3;

			for (;;) {
				writef("\t\tthis is CHILD=%d :a:%x\n", id, uget_sp());
			}
		}

		a += 2;

		for (;;) {
			writef("\tthis is child=%d :a:%x\n", id, uget_sp());
		}
	}

	a++;

	for (;;) {
		writef("this is father=%d : a:%x\n", id, uget_sp());
	}
}
