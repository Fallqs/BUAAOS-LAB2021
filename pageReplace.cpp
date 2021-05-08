#include "pageReplace.h"
using namespace std;
const int N=64;
int t[64];
register int cnt=0;
inline void mx(int &x,int y){if(x>y)x=y;}
inline void qry(long *pp,int rnk){
    int old=0;
    for(int i=0;i<N;++i){
        if(pp[i]==rnk){t[i]=++cnt;return;}
        if(t[i]<t[old])old=i;
    }
    pp[old]=rnk;t[old]=++cnt-10;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
