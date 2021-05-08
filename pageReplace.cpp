#include "pageReplace.h"
using namespace std;
const int N=64,I=64,E=3;
int t[64];
unsigned long long v;
int cnt=0;
inline void mx(int &x,int y){if(x>y)x=y;}
inline void qry(long *pp,int rnk){
    int ex=0,old=ex;
    for(int i=ex,j=ex+I;i<j;++i){
        if(t[i])t[i]=(t[i]<<3)-t[i]>>3;
        if(pp[i]==rnk){mx(t[i]+=1<<25,1<<27);return;}
        if(t[i]<t[old])old=i;
    }
    pp[old]=rnk;t[old]=1<<25;
}
void pageReplace(long * physic_memery, long nwAdd){
    qry(physic_memery, nwAdd>>12);
}
