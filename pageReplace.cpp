#include "pageReplace.h"
using namespace std;
const int N=64;
struct pg{
    pg *l,*r;int rnk;
};
char id[1<<20];
pg buf[N+1],*ll,*rr;
const pg *lst=buf+1;
inline void push(pg *p){
    if(!rr)rr=p;
    else{
        rr->r=p;p->l=rr;rr=p;
    }
    if(!ll)ll=p;
}
inline void pushbk(pg *p){
    if(!ll)ll=p;
    else{
        ll->l=p;p->r=ll;ll=p;
    }
    if(!rr)rr=p;
}
inline pg* pop(){
    return (ll=ll->r)->l;
}
inline pg* del(pg *p){
    if(p->r)p->r->l=p->l;
    if(p->l)p->l->r=p->r;
    if(p==ll)ll=ll->r;
    if(p==rr)rr=rr->l;
    p->r=0;
    return p;
}
int sz;
inline void ins(long *pp,int r){
    int ind=id[r];pg *p;
    if(ind){
        push(del(buf+ind));
        return;
    }else if(sz<N){
        pp[sz]=r;
        p=buf+(++sz);
        push(p);
    }else{
        pp[ll-lst]=r;
        id[ll->rnk]=0;
        push(del(p=ll));
    }
    p->rnk=r;
    id[r]=p-buf;
}
void pageReplace(long * physic_memery, long nwAdd){
    ins(physic_memery, nwAdd>>12);
}
