#include "pageReplace.h"
using namespace std;
const int N=64;
int t[64];
int cnt=128;
inline void mx(int &x,int y){if(x>y)x=y;}
inline void qry(long *pp,int rnk){
    register int old=0;
    for(register int i=0;i<N;++i){
        if(pp[i]==rnk){t[i]=++cnt-((t[i]&1)<<2)<<1;return;}
        if(t[i]<t[old])old=i;
    }
    pp[old]=rnk;t[old]=++cnt-35<<1|1;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
