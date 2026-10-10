typedef int s32;
typedef unsigned short u16;

struct Pair {
    u16 normal;
    u16 alt;
};

struct Obj {
    s32 unk0;
    s32 flags;
    char pad8[8];
    s32 ids[16];
    s32 altIds[16];
};

extern Pair D_008A1610[];

extern "C" u16 func_00552BB0(Obj *o, s32 i, s32 useAlt) {
    Pair *p;
    if (useAlt == 0)
        p = &D_008A1610[o->ids[i]];
    else
        p = &D_008A1610[o->altIds[i]];
    if (o->flags & 0x22)
        return p->alt;
    return p->normal;
}
