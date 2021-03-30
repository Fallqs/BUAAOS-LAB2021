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
struct{int s;char b,c;int d;}st1={5,'a','x',9};
struct{int s;int c[4];}st2;
int main()
{
	printf("main.c:\tmain is start ...\n");
	printf("blabla%$1Tblla\n",&st1);
	st2.s=4;
	st2.c[0]=1;st2.c[1]=2;st2.c[2]=-3;st2.c[3]=-4;
	printf("qaq%04$2Tqaq\n",&st2);
	mips_init();
	panic("main is over is error!");

	return 0;
}
