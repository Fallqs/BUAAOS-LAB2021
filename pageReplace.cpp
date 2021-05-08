#include "pageReplace.h"
using namespace std;
const int N=64,I=8,E=3;
int r[64],t[64];
unsigned long long v;
int cnt=0;
inline void qry(long *pp,int rnk){
    int ex=rnk&0x38,old=ex;
    for(int i=ex,j=ex+I;i<j;++i){
        if(r[i]==rnk){t[i]=++cnt;return;}
        if(t[i]<t[old])old=i;
    }
    pp[old]=r[old]=rnk;t[old]=++cnt;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
