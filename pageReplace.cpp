#include "pageReplace.h"
using namespace std;
const int N=64,M=466,Q=16,R=48;
int t[64],cnt=M;
inline void qry(register long *pp,register int rnk){
	register int j=(rnk&3)<<4,*old=t+j;
	register long *p=pp+j,*end=p+Q; j=++cnt;
	for(register int *i=old;p<end;++p,++i){
		if(*p==rnk){*i=j;return;}
		if(*i<*old)old=i;
	}
	*(pp+(old-t))=rnk;*old=j-M;
}
void pageReplace(long * physic_memery, long nwAdd){
	qry(physic_memery, nwAdd>>12);
}
