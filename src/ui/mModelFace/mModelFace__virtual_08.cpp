typedef int s32;
typedef short s16;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
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

struct mModelFace {
    char pad0[0xA0];
    char unkA0[0x4C];
    char unkEC[0x68];
    char unk154[0x18C];
    s32 unk2E0;
    char pad2E4[0x18];
    f32 unk2FC[3];
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
    unsigned b6 : 1;
    unsigned b7 : 1;
    unsigned b8 : 1;
};

extern char mModelFace__tf[];
extern char hObject__tf[];

extern "C" void mSceneViewFace__virtual_08(mModelFace *, hObject *);
extern "C" mModelFace *func_005C0FC8(s32, void *, s32, void *, void *, void *);
extern "C" void *func_002BE7F8(mModelFace *);
extern "C" void func_002BE800(mModelFace *, void *);
extern "C" void func_002BE988(Str *, mModelFace *);
extern "C" void func_002BE9E8(mModelFace *, Str *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void *func_002BEB60(mModelFace *);
extern "C" void func_002BEB68(mModelFace *, void *);
extern "C" void *func_0021A818(void *);
extern "C" void func_0021A828(void *, void *);
extern "C" void *func_0021A848(void *);
extern "C" void func_0021A858(void *, void *);
extern "C" void func_002024F0(void *, void *);
extern "C" void func_00211208(void *, void *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void mModelFace__virtual_08(mModelFace *self, hObject *src) {
    mModelFace *o;
    Str tmp;

    o = 0;
    mSceneViewFace__virtual_08(self, src);
    if (src != 0) {
        TypeEntry *t = src->vtbl;
        o = func_005C0FC8(t->type, mModelFace__tf, 0, (char *)src + t->offset, hObject__tf, src);
    }
    if (o != 0) {
        func_002BE800(self, func_002BE7F8(o));
        self->b2 = o->b2;
        self->b3 = o->b3;
        self->b4 = o->b4;
        func_002BE988(&tmp, o);
        func_002BE9E8(self, &tmp);
        str_release(&tmp);
        self->b6 = o->b6;
        self->b7 = o->b7;
        self->b8 = o->b8;
        func_002BEB68(self, func_002BEB60(o));
        self->unk2E0 = o->unk2E0;
        func_0021A828(self->unkA0, func_0021A818(o->unkA0));
        func_0021A858(self->unkA0, func_0021A848(o->unkA0));
        {
            f32 *d = self->unk2FC;
            d[0] = o->unk2FC[0];
            d[1] = o->unk2FC[1];
            d[2] = o->unk2FC[2];
        }
        func_002024F0(self->unkEC, o->unkEC);
        func_00211208(self->unk154, o->unk154);
    }
}
