typedef int s32;
typedef unsigned int u32;

struct Obj4 {
    char pad0[0x10];
    s32 unk10;
};

struct Obj3 {
    char pad0[0x80];
    Obj4 *unk80;
};

struct Obj2 {
    char pad0[0x4];
    Obj3 *unk4;
};

struct Obj1 {
    char pad0[0x80];
    Obj2 *unk80;
};

struct Obj0 {
    char pad0[0x6C];
    Obj1 *unk6C;
};

extern "C" s32 func_003411A8(struct Obj0 *arg0) {
    s32 masked = arg0->unk6C->unk80->unk4->unk80->unk10 & 0x800000;
    return 0 != masked;
}
