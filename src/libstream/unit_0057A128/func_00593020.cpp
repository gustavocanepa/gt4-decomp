typedef short s16;
typedef int s32;
typedef unsigned char u8;

struct VEntry {
    s16 delta;
    s16 pad2;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[0x50];
    VEntry *vtbl2;
};

struct P1 {
    ObjA *obj;
    char pad4[0x1A - 4];
    u8 unk1A;
};

struct Self {
    P1 *p1;
};

extern "C" Self *func_00593020(Self *arg0) {
    ObjA *a1 = arg0->p1->obj;
    VEntry *entry = a1->vtbl2 + 11;
    s32 result = entry->fn((char *)a1 + entry->delta);
    if (result != 0) {
        P1 *p1 = arg0->p1;
        p1->unk1A = p1->unk1A | 4;
    }
    return arg0;
}
