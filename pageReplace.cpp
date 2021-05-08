nclude "pageReplace.h"
using namespace std;
const long N=1<<20,M=63;
struct pg{
    pg* l,r;
    long ind;
    pg(){l=r=NULL;ind=-1;}
};
pg lst[N],*ll=lst,*rr=lst;
struct free{
    long fre[M+1],*top;
    free(){
        top=fre+M;
        for(long *p=fre,i=0;p<=top;++p,++i)*p=i;
    }
} f;
inline void pop(){
    *(f.top++) = ll->ind;
    ll->ind = -1;
    ll = ll->r;
}
inline long* alloc(){
    if(f.top==f.fre)pop();
    return *(f.top--);
}
inline void push(long *tb, long id){
    pg *p = lst+id;
    if(~p->ind){
        p->l->r = p->r;
        p->r->l = p->l;
        p->l = rr;
        rr = p;
    }else{
        tb[p->ind = alloc()] = id;
    }
}
void pageReplace(long * physic_memery, long nwAdd){
    push(physic_memery, nwAdd>>12)
}
