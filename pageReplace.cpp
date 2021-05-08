#include "pageReplace.h"
using namespace std;
#define NULL 0
const long N = 3;
struct pg {
    pg *l, *r;
    long rnk;
};
pg buf[N + 1], *lst = buf + 1, *ll = lst, *rr = buf;
int sz;
short id[1 << 20];

inline void ins(long *pp, int rnk) {
    pg *p;
    if (sz < N) {
        p = lst + (sz++);
    } else {
        id[(p=ll)->rnk] = 0;
        //        printf("ll:lst[%d] = %d\n",ll-lst,ll->rnk);
        ll = ll->r;

    }
    rr->r = p;
    p->l = rr;
    rr = p;
    id[rr->rnk = rnk] = rr - buf;
    *(pp + (rr - lst)) = rnk;
}

inline void qry(long *pp, int rnk) {
    int ind = id[rnk];
    if (ind) {
        pg *p = buf + ind;
        if(p!=rr){
            rr->r = p;
            if(p!=ll)p->l->r = p->r;
            else ll = ll->r;
            p->r->l = p->l;
            p->l = rr;
            rr = p;
        }
    } else ins(pp, rnk);
}

void pageReplace(long *physic_memery, long nwAdd) {
    qry(physic_memery, nwAdd >> 12);
}
