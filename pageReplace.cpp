#include "pageReplace.h"
using namespace std;
const int N=64,M=340;
int t[64],cnt=M;
inline void qry(register long *pp,register int rnk){
    register int *old=t,j=++cnt;
    register long *end=pp+N,*p=pp;
    for(register int *i=t;p<end;++p,++i){
        if(*p==rnk){*i=j;return;}
        if(*i<*old)old=i;
    }
    *(pp+(old-t))=rnk;*old=j-M;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
