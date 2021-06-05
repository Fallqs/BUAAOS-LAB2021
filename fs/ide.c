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
	int current;
	while (offset_begin + offset < offset_end) {
		// Your code here
		// error occurred, then panic.
		current = offset_begin + offset;
		//write diskno
		if (syscall_write_dev(&diskno,0x13000010,4) < 0) {
			user_panic("panic in ide_read 1");
		}
		//write offset
		if (syscall_write_dev(&current,0x13000000,4) < 0) {
			user_panic("panic in ide_read 2");
		}
		//write ready to read
		int ready = 0;
		if (syscall_write_dev(&ready,0x13000020,4) < 0) {
			user_panic("panic in ide_read 3");
		}
		//read result error on 0
		int ret;
		if (syscall_read_dev(&ret,0x13000030,4) < 0) {
			user_panic("panic in ide_read 4");
		}
		if (!ret) {
			user_panic("panic in ide_read 5");
		}
		//read from buffer
		if (syscall_read_dev(dst,0x13004000,512) < 0) {
			user_panic("panic in ide_read 6");
		}
		offset += 512;
		dst += 512;	}
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
	// int offset_begin = ;
	// int offset_end = ;
	// int offset = ;
	int offset_begin = secno * 0x200;
	int offset_end = offset_begin + nsecs * 0x200;
	int offset = 0;
	int current;	// DO NOT DELETE WRITEF !!!
	writef("diskno: %d\n", diskno);

	// while ( < ) {
	// copy data from source array to disk buffer.

	// if error occur, then panic.
	// }
	while(offset_begin + offset < offset_end) {
		// copy data from source array to disk buffer.
		// if error occur, then panic.
		current = offset_begin + offset;
		//write data to buffer
		if (syscall_write_dev(src,0x13004000,512) < 0) {
			user_panic("panic in ide_write 1");
		}
		//write diskno
		if (syscall_write_dev(&diskno,0x13000010,4) < 0) {
			user_panic("panic in ide_write 2");
		}
		//write offset
		if (syscall_write_dev(&current,0x13000000,4) < 0) {
			user_panic("panic in ide_write 3");
		}
		//ready to write buffer to disk
		int ask = 1;
		if (syscall_write_dev(&ask,0x13000020,4) < 0) {
			user_panic("panic in ide_write 4");
		}
		int ret;
		if (syscall_read_dev(&ret,0x13000030,4) < 0) {
			user_panic("panic in ide_write 5");
		}
		if (!ret) {
			user_panic("panic in ide_write 6");
		}
		src += 512;
		offset += 512;
	}
}

