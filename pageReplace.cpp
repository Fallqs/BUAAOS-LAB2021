#include "pageReplace.h"
using namespace std;
const int N=64,M=410,Q=16,R=48;
int t[64],sz[64],cnt=M;
void pageReplace(long *p,long nwAdd){
	register int rnk=nwAdd>>12, j=(rnk&3)<<4;
	if(sz[j]<Q){
		register int end=j+(sz[j]++);
		for(;j<end;++j)
			if(p[j]==rnk){t[j]=++cnt;return;}
		p[end]=rnk;t[end]=++cnt;
		return;
	}
	register int old=j;
	for(register int end=j+Q;j<end;++j){
		if(p[j]==rnk){t[j]=++cnt;return;}
		if(t[j]<t[old])old=j;
	}
	p[old]=rnk;t[old]=++cnt;
}
