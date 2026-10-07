typedef int s32;
typedef unsigned char u8;

struct S00463BB8 {
    char pad[0x544];
    u8 unk544;
};

struct Obj {
    char pad0[0xE4];
    s32 unkE4;
    S00463BB8 *unkE8;
};

extern "C" s32 func_00463BB8(Obj *arg0) {
    S00463BB8 *p = arg0->unkE8;
    s32 base = arg0->unkE4;
    s32 idx = p->unk544;
    return *(s32 *)(0x10024 + idx * 4 + base);
}
