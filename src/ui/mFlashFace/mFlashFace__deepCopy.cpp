/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };
struct Ent { s16 delta; s16 index; char *ptr; };

struct Flags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
};
struct Obj {
    char pad0[4];
    Ent *vt;
    char pad1[0xB4 - 8];
    Flags f;
};

extern "C" void mWidget__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, s32, void *, void *, void *);
extern "C" void func_00293978(Str *, void *);
extern "C" void func_002939D8(Obj *, Str *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern char mFlashFace__tf[];
extern char hObject__tf[];

extern "C" void mFlashFace__deepCopy(Obj *self, Obj *src) {
    Obj *r = 0;
    mWidget__deepCopy(self, src);
    if (src != 0) {
        Ent *e = src->vt;
        r = (Obj *)__dynamic_cast_2(e->ptr, mFlashFace__tf, 0, (char *)src + e->delta, hObject__tf, src);
    }
    if (r != 0) {
        Str tmp;
        func_00293978(&tmp, r);
        func_002939D8(self, &tmp);
        {
            Rep *q = (Rep *)(tmp.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        self->f.b0 = r->f.b0;
        self->f.b1 = r->f.b1;
        self->f.b2 = r->f.b2;
        self->f.b4 = r->f.b4;
        self->f.b5 = r->f.b5;
        self->f.b6 = r->f.b6;
    }
}
