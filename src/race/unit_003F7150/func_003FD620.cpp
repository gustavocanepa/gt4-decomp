/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent2 { short off; short pad; int (*fn)(void *, int); };
struct Ent1 { short off; short pad; int (*fn)(void *); };
struct VT { char p[0x438]; Ent2 e438; char p1[8]; Ent2 e448; char p2[8]; Ent2 e458; };
struct VT2 { char p[0x148]; Ent1 e148; };
struct Obj { char p[0x64]; VT *vt; };
struct Big { char p[0x10140]; VT2 *vt; };
struct TI { short off; short pad; void *x; };
struct H { char p[0x64]; TI *ti; };
struct Cnt { int n; };
struct Owner { char p[0x60]; Cnt *cnt; char p1[0x20]; H *h; };
struct In { char p[0x18]; int v; };
struct Arg2 { char p[0xc]; short c; short pc; In *x; };
extern char RacePS2Base__tf[];
extern char RaceBase__tf[];
extern "C" int DynamicsConductor__GetCountDown(void *, int);
extern "C" int func_0035AE58(int);
extern "C" int func_003F7880(int, int) throw();
extern "C" Obj *__dynamic_cast_2(void *, void *, int, void *, void *, void *);

extern "C" int func_003FD620(Owner *a0, Big *a1, Arg2 *a2, int a3, int *out)
{
    int r = 0;
    In *input = a2->x;
    *out = 0;
    if (input == 0) return r;
    Obj *o = 0;
    int s2 = input->v;
    H *h = a0->h;
    if (h) {
        TI *t = h->ti;
        o = __dynamic_cast_2(t->x, RacePS2Base__tf, 0, (char *)h + t->off, RaceBase__tf, h);
    }
    if (func_0035AE58(s2)) {
        Ent2 *e = &o->vt->e438;
        r = 1;
        if (e->fn((char *)o + e->off, a2->c)) return r;
    }
    Ent2 *e = &o->vt->e458;
    r = 2;
    if (e->fn((char *)o + e->off, a2->c)) return r;
    Ent2 *f = &o->vt->e448;
    r = 3;
    if (f->fn((char *)o + f->off, a2->c)) return r;
    r = 4;
    if (func_003F7880(s2, 0) == 1) return r;
    Ent1 *g = &a1->vt->e148;
    if (g->fn((char *)a1 + g->off)) {
        int n = a0->cnt->n;
        for (int i = 1; i < n; i++) {
            if (DynamicsConductor__GetCountDown(a1, i) == 1) {
                *out = i;
                return 5;
            }
        }
    }
    return a3;
}
