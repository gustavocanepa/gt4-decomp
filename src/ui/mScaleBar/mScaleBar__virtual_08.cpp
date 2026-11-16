/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef s32 (*Fn)(char *);
struct Entry { s16 delta; s16 index; Fn fn; };
struct Obj { char pad[4]; Entry *vt; };
struct T { char pad[0xC0]; s32 a; f32 b; f32 c; f32 d; char pad2[8]; f32 e; };
extern "C" void mBox__deepCopy(void *, void *);
extern "C" char mScaleBar__tf[];
extern "C" char hObject__tf[];
extern "C" T *__dynamic_cast_2(Fn, char *, int, char *, char *, Obj *);

extern "C" void mScaleBar__virtual_08(T *arg0, Obj *arg1) {
    T *r;
    mBox__deepCopy(arg0, arg1);
    r = 0;
    if (arg1) {
        Entry *e = arg1->vt;
        r = __dynamic_cast_2(e->fn, mScaleBar__tf, 0, (char *)arg1 + e->delta, hObject__tf, arg1);
    }
    if (r) {
        arg0->a = r->a;
        arg0->b = r->b;
        arg0->c = r->c;
        arg0->d = r->d;
        arg0->e = r->e;
    }
}
