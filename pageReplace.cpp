#include "pageReplace.h"
using namespace std;
const int N=64,M=256;
int t[64],cnt=M;
inline void qry(long *pp,int rnk){
    register int old=0,j=++cnt,r=rnk;
    for(register int i=0;i<N;++i){
        if(pp[i]==r){t[i]=j;return;}
        if(t[i]<t[old])old=i;
    }
    pp[old]=r;t[old]=j-M;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
