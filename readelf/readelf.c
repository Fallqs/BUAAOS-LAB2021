/* This is a simplefied ELF reader.
 * You can contact me if you find any bugs.
 *
 * Luming Wang<wlm199558@126.com>
 */

#include "kerelf.h"
#include <stdio.h>
/* Overview:
 *   Check whether it is a ELF file.
 *
 * Pre-Condition:
 *   binary must longer than 4 byte.
 *
 * Post-Condition:
 *   Return 0 if `binary` isn't an elf. Otherwise
 * return 1.
 */
int is_elf_format(u_char *binary)
{
        Elf32_Ehdr *ehdr = (Elf32_Ehdr *)binary;
        if (ehdr->e_ident[EI_MAG0] == ELFMAG0 &&
                ehdr->e_ident[EI_MAG1] == ELFMAG1 &&
                ehdr->e_ident[EI_MAG2] == ELFMAG2 &&
                ehdr->e_ident[EI_MAG3] == ELFMAG3) {
                return 1;
        }

        return 0;
}

/* Overview:
 *   read an elf format binary file. get ELF's information
 *
 * Pre-Condition:
 *   `binary` can't be NULL and `size` is the size of binary.
 *
 * Post-Condition:
 *   Return 0 if success. Otherwise return < 0.
 *   If success, output address of every section in ELF.
 */

/*
    Exercise 1.2. Please complete func "readelf". 
*/
Elf32_Half rv(Elf32_Half x){
	Elf32_Half ans=0;
	int i=0;for(;i<2;++i)
		{ans=(ans<<8)|(x&255);x>>=8;}
	return ans;
}
Elf32_Addr rev(Elf32_Addr x){
	Elf32_Addr ans=0;
	int i=0;for(;i<4;++i)
		{ans=(ans<<8)|(x&255);x>>=8;}
	return ans;
}
int readelf(u_char *binary, int size)
{
        Elf32_Ehdr *ehdr = (Elf32_Ehdr *)binary;

        int Nr;

        Elf32_Shdr *shdr = NULL;

        u_char *ptr_sh_table = NULL;
        Elf32_Half sh_entry_count;
        Elf32_Half sh_entry_size;


        // check whether `binary` is a ELF file.
        if (size < 4 || !is_elf_format(binary)) {
                printf("not a standard elf format\n");
                return 0;
        }

	int typ = ehdr->e_ident[5];//1->low, 2->high

        // get section table addr, section header number and section header size.
	if(typ==2){
		ptr_sh_table = binary + rv(ehdr->e_shoff);//high->section , low->segment
		sh_entry_size = rv(ehdr->e_shentsize);
		sh_entry_count = rv(ehdr->e_shnum);
	}else if(typ==1){
		ptr_sh_table = binary + ehdr->e_phoff;
		sh_entry_size = ehdr->e_phentsize;
		sh_entry_count = ehdr->e_phnum;
	}
        // for each section header, output section number and section addr. 
        // hint: section number starts at 0.
	Elf32_Word i=0;
	while(i < sh_entry_count) {
		if(typ==2)printf("%d:0x%x\n",i++,rev(((Elf32_Shdr *)ptr_sh_table)->sh_addr));
		else if(typ==1)printf("%d:0x%x,0x%x\n",i++,((Elf32_Phdr *)ptr_sh_table)->p_filesz,((Elf32_Phdr *)ptr_sh_table)->p_memsz);
		ptr_sh_table+=sh_entry_size;
	}	

        return 0;
}

