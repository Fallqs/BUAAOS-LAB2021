#include <asm/regdef.h>
#include <asm/cp0regdef.h>
#include <asm/asm.h>

.text
LEAF(_my_getchar)
	.set	mips2      /*.set is used to instruct how the assembler works and control the order of instructions */
	.set	reorder

	lb a0,0x00(zero)
	beq a0,zero,_my_getchar
	nop
	jal _my_putchar
	nop
END(_my_getchar)

LEAF(_my_putchar)
		.set	mips2      /*.set is used to instruct how the assembler works and control the order of instructions */
	.set	reorder
	sb a0,0x00(zero)
	li t0, 13
	bne a0,t0,RT
	li t0, 10
	sb t0,0x00(zero)
RT:
	nop
END(_my_putchar)

LEAF(_my_exit)
	li t0 ,1
	sb t0, 0x10(zero)
	nop
END(_my_exit)

