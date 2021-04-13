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

int main()
{
	printf("main.c:\tmain is start ...\n");

	printf("f0: %d\n",cal_page(0,0,0,0));
	printf("f1: %x\n",cal_page(1,0x7fcef000,0,0));
	printf("f2: %x\n",cal_page(2,0x7fdff000,1,0));

	mips_init();
	panic("main is over is error!");

	return 0;
}
