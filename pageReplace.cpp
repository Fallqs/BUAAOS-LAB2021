#include "pageReplace.h"
using namespace std;
const int N=64,M=395,Q=8;
int t[64],sz[8],cnt=M;
void pageReplace(long *p,long nwAdd){
	register int rnk(nwAdd>>12), i(rnk&7), j(i<<3);
	if(sz[i]<Q){
		register int end(j+sz[i]);
		for(;j<end;++j)
			if(p[j]==rnk){t[j]=++cnt;return;}
		p[end]=rnk;t[end]=++cnt-M;++sz[i];
		return;
	}
	register int old(j);
	for(register int end(j+Q);j<end;++j){
		if(p[j]==rnk){t[j]=++cnt;return;}
		if(t[j]<t[old])old=j;
	}
	p[old]=rnk;t[old]=++cnt-M;
}
