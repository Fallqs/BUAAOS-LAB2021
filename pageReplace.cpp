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
short id[1 << 20];

inline void ins(long *pp, int rnk) {
    pg *p;
    if (sz < N) {
        p = lst + (sz++);
    } else {
        id[(p=ll)->rnk] = 0;
        ll = ll->r;
    }
    rr->r = p; rr = p;
    id[rr->rnk = rnk] = rr - buf;
    *(pp + (rr - lst)) = rnk;
}

inline void qry(long *pp, int rnk) {
    int ind = id[rnk];
    if (ind) {
        pg *p = buf + ind;
        rr->r = p;
        p->l = rr;
        rr = p;
    } else ins(pp, rnk);
}

void pageReplace(long *physic_memery, long nwAdd) {
    qry(physic_memery, nwAdd >> 12);
}
