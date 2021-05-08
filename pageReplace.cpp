#include "pageReplace.h"
using namespace std;
const int N=64;
int t[64];
int cnt=256;
inline void upd(int &x,int j){
    register int p=x&3;
    register int y=x&2<<5+x&2<<4;
    register int z=x&1<<5;
    x=(j-y-z)<<2|p>>1;
}
inline void qry(long *pp,int rnk){
    register int old=0,j=++cnt;
    for(register int i=0;i<N;++i){
        if(pp[i]==rnk){upd(t[i],j);return;}
        if(t[i]<t[old])old=i;
    }
    pp[old]=rnk;t[old]=j-256<<2|2;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
