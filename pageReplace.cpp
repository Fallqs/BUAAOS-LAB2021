#include "pageReplace.h"
using namespace std;
#define NULL 0
const long N = 64;
struct pg {
    pg *l, *r;
    long rnk;
};
pg buf[N + 1], *lst = buf + 1, *ll = lst, *rr = buf;
int sz;
char id[1 << 20];

inline void ins(long *pp, int rnk) {
    if (sz < N) {
        pg *p = lst + (sz++);
        p->rnk = rnk;
        id[rnk] = p - lst;
        rr->r = p;
        p->l = rr;
        rr = p;
        *(pp + (p - lst)) = rnk;
    } else {
        ll->rnk = rnk;
        id[rnk] = ll - lst;
        *(pp + (ll - lst)) = rnk;
    }
}

inline void qry(long *pp, int rnk) {
    int ind = id[rnk];
    if (ind) {
        pg *p = lst + ind;
        rr->r = p;
        p->l = rr;
        rr = p;
    } else ins(pp, rnk);
}

void pageReplace(long *physic_memery, long nwAdd) {
    qry(physic_memery, nwAdd >> 12);
}
