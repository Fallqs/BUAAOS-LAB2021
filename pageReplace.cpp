#include "pageReplace.h"
using namespace std;
const int N=64,M=410,Q=16,C=256;
int t[N],sz[4],cache[C],*ct[C],cnt=M;
void pageReplace(long *p,long nwAdd){
	register int rnk(nwAdd>>12), ch(rnk&255);
	if(cache[ch]==rnk){*(ct[ch])=++cnt;return;}
	else cache[ch]=rnk;

	register int i(rnk&3), j(i<<4);

	if(sz[i]<Q){
		register int end(j+sz[i]);
		for(;j<end;++j)
			if(p[j]==rnk){
				ct[ch]=t+j;
				t[j]=++cnt;
				return;
			}
		p[end]=rnk;t[end]=++cnt-M;++sz[i];
		ct[ch]=t+end;
	}
	register int old(j);
	for(register int end(j+Q);j<end;++j){
		if(p[j]==rnk){
			ct[ch]=t+j;
			t[j]=++cnt;
			return;
		}
		if(t[j]<t[old])old=j;
	}
	cache[p[old]&255]=0;
	p[old]=rnk;t[old]=++cnt-M;ct[ch]=t+old;
}
