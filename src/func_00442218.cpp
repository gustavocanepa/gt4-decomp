typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct RecA {
    char pad0[0x60];
};

struct RecB {
    char pad0[0x20];
};

struct RecC {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    char pad4[0xC];
};

struct Trip {
    s64 v[3];
};

struct Ids {
    s64 id;
    Trip a;
    Trip b;
};

struct Elem {
    char pad0[0xA8];
};

struct Dst {
    char pad0[0x1C8];
    u8 f1C8;
    char pad1C9;
    u8 f1CA;
    char pad1CB;
    u8 f1CC;
    char pad1CD;
    u8 f1CE;
    char pad1CF[0x41];
    Elem elems[3];
};

extern "C" s32 func_00443ED0(Global *g, s64 id, void *info);
extern "C" void func_00442490(void *ctx, Elem *e, RecA *a, RecB *b);

extern "C" void func_00442218(void *ctx, Dst *dst, Ids *ids) {
    Trip a = ids->a;
    Trip b = ids->b;
    RecA ra;
    RecB rb;
    RecC rc;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_00443ED0(&D_006235A8, a.v[i], &ra);
        func_00443ED0(&D_006235A8, b.v[i], &rb);
        func_00442490(ctx, &dst->elems[i], &ra, &rb);
    }
    func_00443ED0(&D_006235A8, ids->id, &rc);
    dst->f1CA = rc.b2;
    dst->f1CC = rc.b0;
    dst->f1C8 = rc.b3;
    dst->f1CE = 4;
}
