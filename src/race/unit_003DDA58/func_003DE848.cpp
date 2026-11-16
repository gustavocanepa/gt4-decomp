/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEnt { s16 delta; s16 pad; void *tf; };
struct VEntF { s16 delta; s16 pad; s32 (*fn)(void *, void *, void *); };
struct VEntG { s16 delta; s16 pad; void (*fn)(void *, void *); };
struct Hdr { char pad[4]; s32 size; };
struct VT2 { char pad[4]; };
struct Obj2 { char pad[0x64]; char *vt; };
struct Glob { char pad[0x84]; Obj2 *f84; };
struct VT { char pad[0x30]; VEntF e30; };
struct Self { VT *vt; };

extern Glob *D_00621CB4;

extern "C" void RaceSolitaire__tf(void);
extern "C" void RaceBase__tf(void);
extern "C" void *__dynamic_cast_2(void *, void (*)(void), s32, void *, void (*)(void), void *);
extern "C" char *Serialize__Base__getHeader(void *, void *);

extern "C" s32 func_003DE848(Self *self, void *a1, void *a2) {
    Hdr h;
    char *p = Serialize__Base__getHeader(&h, a1);
    VEntF *e = &self->vt->e30;
    if (e->fn((char *)self + e->delta, a1, a2) == 2) {
        return 0;
    }
    Obj2 *o = D_00621CB4->f84;
    Obj2 *c = 0;
    if (o != 0) {
        VEnt *t = (VEnt *)o->vt;
        c = (Obj2 *)__dynamic_cast_2(t->tf, RaceSolitaire__tf, 0, (char *)o + t->delta, RaceBase__tf, o);
    }
    if (c == 0) {
        VEntG *g1 = (VEntG *)(o->vt + 0x1F8);
        g1->fn((char *)o + g1->delta, p);
        VEntG *g2 = (VEntG *)(o->vt + 0x200);
        g2->fn((char *)o + g2->delta, p);
    } else {
        VEntG *g3 = (VEntG *)(c->vt + 0x4E0);
        g3->fn((char *)c + g3->delta, p);
    }
    return (s32)(p + h.size);
}
