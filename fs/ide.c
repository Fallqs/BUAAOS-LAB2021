/*
 * operations on IDE disk.
 */

#include "fs.h"
#include "lib.h"
#include <mmu.h>

// Overview:
// 	read data from IDE disk. First issue a read request through
// 	disk register and then copy data from disk buffer
// 	(512 bytes, a sector) to destination array.
//
// Parameters:
//	diskno: disk number.
// 	secno: start sector number.
// 	dst: destination for data read from IDE disk.
// 	nsecs: the number of sectors to read.
//
// Post-Condition:
// 	If error occurred during read the IDE disk, panic. 
// 	
// Hint: use syscalls to access device registers and buffers
void
ide_read(u_int diskno, u_int secno, void *dst, u_int nsecs)
{
	// 0x200: the size of a sector: 512 bytes.
	int offset_begin = secno * 0x200;
	int offset_end = offset_begin + nsecs * 0x200;
	int offset = 0;
	u_int dev = 0x13000000;
	u_char op = 0;

	while (offset_begin + offset < offset_end) {
            // Your code here
            // error occurred, then panic.
		u_int ofs = offset_begin + offset;
		if( syscall_write_dev( (u_int)	&diskno, 	dev + 0x10, 	4) ||
			syscall_write_dev( (u_int)	&ofs, 		dev + 0x0,  	4) ||
			syscall_write_dev( (u_int)	&op,  		dev + 0x20, 	1) )
			user_panic("ide_read COMMAND error");

		if( syscall_read_dev(  (u_int)	&op,  		dev + 0x30, 	1) || op == 0)
			user_panic("ide_read FAILED");

		if( syscall_read_dev(  (u_int)(dst + ofs),	dev + 0x400, 	0x200))
			user_panic("ide_read CONTENT error");

		offset += 0x200;
	}
}


// Overview:
// 	write data to IDE disk.
//
// Parameters:
//	diskno: disk number.
//	secno: start sector number.
// 	src: the source data to write into IDE disk.
//	nsecs: the number of sectors to write.
//
// Post-Condition:
//	If error occurred during read the IDE disk, panic.
//	
// Hint: use syscalls to access device registers and buffers
void
ide_write(u_int diskno, u_int secno, void *src, u_int nsecs)
{
        // Your code here
	int offset_begin = secno * 0x200;
	int offset_end = offset_begin + nsecs * 0x200;
	int offset = 0;
	u_int dev = 0x13000000;
	u_char op = 1;

		// DO NOT DELETE WRITEF !!!
	writef("diskno: %d\n", diskno);

	while (offset_begin + offset < offset_end) {
            // Your code here
            // error occurred, then panic.
		u_int ofs = offset_begin + offset;
		if( syscall_write_dev( (u_int)	&diskno, 	dev + 0x10, 	4) ||
			syscall_write_dev( (u_int)	&ofs, 		dev + 0x0,  	4) )
					user_panic("ide_write COMMAND error");

		if( syscall_write_dev( (u_int)(src + ofs),	dev + 0x400, 	0x200))
			user_panic("ide_read CONTENT error");

		if( syscall_write_dev( (u_int)	&op,  		dev + 0x20, 	1) ||
			syscall_read_dev(  (u_int)	&op,  		dev + 0x30, 	1) || op == 0)
			user_panic("ide_write FAILED");

		offset += 0x200;
	}
}

