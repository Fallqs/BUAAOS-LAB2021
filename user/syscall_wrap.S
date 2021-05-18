#include <asm/regdef.h>
#include <asm/cp0regdef.h>
#include <asm/asm.h>

/*** exercise 4.1 ***/
LEAF(msyscall)
    // TODO: you JUST need to execute a `syscall` instruction and return from msyscall
    syscall
    jr ra
    nop

END(msyscall)

LEAF(gtsp)
addiu v0, sp, 0
addiu v1, sp, 0
jr ra
nop
END(gtsp)

