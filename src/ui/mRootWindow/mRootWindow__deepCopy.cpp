#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct TypeEntry {
    s16 offset;
    s16 pad2;
    s32 type;
};

struct hObject {
    s32 unk0;
    TypeEntry *vtbl;
};

struct Obj {
    char pad0[0xDC];
    char *dc;
    char *e0;
    f32 fe4;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
};

extern char mRootWindow__tf[];
extern char hObject__tf[];

extern "C" void mBox__deepCopy(void *a, void *b);
extern "C" Obj *__dynamic_cast_2(s32 a0, void *a1, s32 a2, void *a3, void *a4, void *a5);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void mRootWindow__deepCopy(Obj *arg0, hObject *arg1) {
    Obj *o = 0;
    mBox__deepCopy(arg0, arg1);
    if (arg1 != 0) {
        TypeEntry *t = arg1->vtbl;
        o = __dynamic_cast_2(t->type, mRootWindow__tf, 0, (char *)arg1 + t->offset, hObject__tf, arg1);
    }
    if (o != 0) {
        arg0->b4 = o->b4;
        arg0->b5 = o->b5;
        arg0->fe4 = o->fe4;
        arg0->b0 = o->b0;
        arg0->b1 = o->b1;
        arg0->b2 = o->b2;

        char **p4 = &arg0->dc;
        char **p5 = &o->dc;
        if (p5 != p4) {
            Rep *q = (Rep *)(*p4 - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
            char *src = *p5;
            Rep *r = (Rep *)(src - 0x10);
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                r->ref++;
                d = src;
            }
            *p4 = d;
        }

        char **e4 = &arg0->e0;
        char **e5 = &o->e0;
        if (e5 != e4) {
            Rep *q = (Rep *)(*e4 - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
            char *src = *e5;
            Rep *r = (Rep *)(src - 0x10);
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                r->ref++;
                d = src;
            }
            *e4 = d;
        }
    }
}
