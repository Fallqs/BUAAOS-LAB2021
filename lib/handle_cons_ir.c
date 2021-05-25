#include<printf.h>

void print_situation(int v){
	printf("%x\n",v);
}

int tt(){
	int ans=1;
	bcopy((void*)&ans, (void*)(0x15000000+0x0000+0xa0000000), 4);
	bcopy((void*)(0x15000000+0x0010+0xa0000000),(void*)&ans,4);
	return ans;
}

void handle_cons_ir(char c, int status){
	static int cnt=0;
	static int nw=0;
	int itv;
	if(!cnt++){
		printf("CP0 STATUS: %x, 1st interrupt: %d\n", status, nw = tt());
	}else{
		printf("interval: %d\n", itv = tt()-nw);
	}

	static char buf[256];
	static int len=0;
	//printf("cp0 status: %x\n",status);
	buf[len++]=c;
	if(itv>=5){
		buf[len]='\0';
		printf("length=%d, string=%s\n", len, buf);
		bcopy((void*)(0x10000000+0x0010+0xa0000000),(void*)&buf,1);
	}

}
