#include "pageReplace.h"
using namespace std;
const int N=64,M=410,Q=16;
int t[64],cnt=M;
inline void qry(register long *pp,register int rnk){
	register int j=(rnk&3)<<4;
	for(register long *p=pp+j,*end=p+Q;p<end;++p)
		if(*p==rnk){*(t+(p-pp))=++cnt;return;}
	register int *old=t+j;j=*old;
	for(register int *i=old,*end=old+Q;i<end;++i)
		if(*i<j)j=*(old=i);
	*(pp+(old-t))=rnk;*old=++cnt-M;
}
void pageReplace(long * physic_memery, long nwAdd){
	qry(physic_memery, nwAdd>>12);
}
