/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Vec4 { f32 x, y, z, w; };
struct VT0 { short delta; short pad; void *ti; };
struct Base { int x; VT0 *vt; };
struct VE { short delta; short index; f32 (*fn)(void *, int); };
struct Obj {
    int x;
    VE *vt;
    char pad8[0xC4 - 8];
    char unkC4[1];
};

extern char mRenderContextPS2__tf[];
extern char mRenderContext__tf[];

extern "C" void mBox__virtual_92(void *, void *);
extern "C" void func_002180E0(void *, void *);
extern "C" void func_00218170(void *, void *, Vec4 *, f32);
extern "C" f32 func_002313E0(void *);
extern "C" f32 func_00231400(void *);
extern "C" f32 func_00231420(void *);
extern "C" f32 func_00231440(void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);

extern "C" void mColorWindow__virtual_92(Obj *self, Base *arg1) {
    Vec4 v;
    void *p = 0;
    char *s3 = self->unkC4;
    if (arg1 != 0) {
        VT0 *t = arg1->vt;
        p = __dynamic_cast_2(t->ti, mRenderContextPS2__tf, 0, (char *)arg1 + t->delta, mRenderContext__tf, arg1);
    }
    func_002180E0(p, s3);
    mBox__virtual_92(self, arg1);
    f32 a = func_002313E0(arg1);
    f32 b = func_00231400(arg1);
    f32 c = func_00231420(arg1);
    f32 d = func_00231440(arg1);
    v.x = a;
    v.y = b;
    v.z = c;
    v.w = d;
    VE *e = &self->vt[57];
    f32 r = e->fn((char *)self + e->delta, 0);
    func_00218170(p, s3, &v, r);
}
