#include<printf.h>

void print_situation(int v){
	printf("%x\n",v);
}

void handle_cons_ir(char c, int status){
	static char buf[70];
	static int len=0;
	printf("cp0 status: %x\n",status);
	if(c!='\r')buf[len++]=c;
	else{
		buf[len]='\0';
		printf("length: %d\n",len);
		printf("contnt: %s\n",buf);
	}
}
