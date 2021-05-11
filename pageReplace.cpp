#include "pageReplace.h"
using namespace std;
const int N=64,M=410,Q=16,R=48;
int t[64],sz[64],cnt=M;
void pageReplace(long *physic_memery,long nwAdd){
	register int rnk=nwAdd>>12, j=(rnk&3)<<4;
	if(sz[j]<Q){
		register int end=j+sz[j], jj=j;
		for(;j<end;++j)
			if(physic_memery[j]==rnk){t[j]=++cnt;return;}
		physic_memery[end]=rnk;t[end]=++cnt;++sz[jj];
		return;
	}
	register int old=j;
	for(register int end=j+Q;j<end;++j){
		if(physic_memery[j]==rnk){t[j]=++cnt;return;}
		if(t[j]<t[old])old=j;
	}
	physic_memery[old]=rnk;t[old]=++cnt;
}
