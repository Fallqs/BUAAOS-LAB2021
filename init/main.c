/*
 * Copyright (C) 2001 MontaVista Software Inc.
 * Author: Jun Sun, jsun@mvista.com or jsun@junsun.net
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 *
 */

#include <printf.h>
#include <pmap.h>
//struct{int s;char b,c;int d;}st2={5,'a','x',9};
int main()
{
	printf("main.c:\tmain is start ...\n");
//	printf("%04$1T\n",&st2);
	mips_init();
	panic("main is over is error!");

	return 0;
}
