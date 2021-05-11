#include "pageReplace.h"
using namespace std;
const int N=64,M=410,Q=16,R=48;
int t[64],sz[64],cnt=M;
inline void pageReplace(long *pp,long rnk){
	register int j=(rnk&3)<<4;
	if(sz[j]<Q){
		register int end=j+sz[j];
		for(;j<end;++j)
			if(p[j]==rnk){t[j]=++cnt;return;}
		p[end]=rnk;t[end]=++cnt;++sz[j];
		return;
	}
	register int old=j;
	for(register int end=j+Q;j<end;++j){
		if(p[j]==rnk){t[j]=++cnt;return;}
		if(t[j]<t[old])old=j;
	}
	p[old]=rnk;t[old]=++cnt;
}
