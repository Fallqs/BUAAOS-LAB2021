#include "pageReplace.h"
using namespace std;
const int N=64;
int t[64];
int cnt=256;
inline void mx(int &x,int y){if(x>y)x=y;}
inline void qry(long *pp,int rnk){
    register int old=0,j=++cnt;
    for(register int i=0,tmp;i<N;++i){
        if(pp[i]==rnk){
            tmp=t[i]&1;
            t[i]=j-(tmp<<5)-(tmp<<4)<<1;
            return;
        }
        if(t[i]<t[old])old=i;
    }
    pp[old]=rnk;t[old]=j-255<<1|1;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
