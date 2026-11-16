/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short idx; int (*fn)(void *); };
struct Vt { char pad[0xB8]; VE e; };
struct Fb { Vt *vt; };
struct Inner { char pad[0x4C]; Vt *vtbl; char pad2[0x150 - 0x50]; int pad150; int f154; int f158; };
struct Holder { char pad[0x10]; Inner *f10; };
struct Obj { char pad[0x4C]; struct { short d; short i; int a; } *v; };
extern "C" void func_001740F0(void *, int);
extern "C" void func_00174148(void *, void *);
extern "C" void func_00197878(void *, int) throw();
extern "C" void func_001978D0(void *, void *) throw();
extern "C" void func_0019B010(int, int, int, int);
extern "C" Inner *__dynamic_cast_2(int, void *, int, void *, void *, void *);
extern char D_005D1260[];
struct T { Holder *h; int p[3]; };
struct U { int v; int p[3]; };
extern char D_005D1DB0[];
extern "C" void MPhotoRenderFace__setPhotoFile(void *a0, void *a1, int n, void *a3) {
    if (n > 0) {
        T h;
        Inner *r = 0;
        func_00174148(&h, a3);
        if (h.h->f10 != 0) {
            Obj *o = (Obj *)h.h->f10;
            r = __dynamic_cast_2(o->v->a, D_005D1DB0, 0, (char *)o + o->v->d, D_005D1260, o);
        }
        if (r != 0) {
            U s3obj; U *s3 = &s3obj;
            func_001978D0(s3, a1);
            int sv = s3->v;
            VE *e = &r->vtbl->e;
            int *q = (int *)((char *)r + 0x150);
            int s1 = q[1];
            int s0 = q[2] - s1;
            int v = e->fn((char *)r + e->delta);
            func_0019B010(sv, s1, s0, v);
            func_00197878(s3, 2);
        }
        func_001740F0(&h, 2);
    }
}
