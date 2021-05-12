#include "pageReplace.h"
using namespace std;
const int N=64,M=410,Q=16,C=256;
int t[64],sz[4],cnt=M,cache[C]={-1},*ct[C];
void pageReplace(long *pp,long nwAdd){
	register int rnk(nwAdd>>12), ch=rnk&255;
	if(cache[ch]==rnk){*ct[ch]=++cnt;return;}
	register int i(rnk&3), j(i<<4);
	if(sz[i]<Q){
		cache[ch]=rnk;
		register int end(j+sz[i]);
		for(register long *p=pp+bs,*pend=p+end;p<pend;++p)
			if(*p==rnk){ *(ct[ch]=t+(p-pp))=++cnt; return;}
		p[end]=rnk;t[end]=++cnt-M;
		++sz[i];ct[ch]=t+end;
		return;
	}
	register int *old(t+j);j=*old;
	register long *p=pp+bs,*pend=p+Q;
	for(register int *i(old);p<pend;++p,++i){
		if(*p==rnk){
			cache[ch]=rnk;
			*(ct[ch]=i)=++cnt;
			return;
		}
		if(*i<j)j=*(old=i);
	}
	p=pp+(old-t);
	cache[*p&255]=0;cache[ch]=rnk;
	*p=rnk;*old=++cnt-M;ct[ch]=old;
}
