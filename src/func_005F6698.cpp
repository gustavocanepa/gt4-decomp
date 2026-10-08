typedef int s32;

struct D {
    char pad0[0x80];
    s32 unk80;
};

struct C {
    char pad0[4];
    D *unk4;
};

struct B {
    char pad0[0x80];
    C *unk80;
};

struct Obj {
    char pad0[0x6C];
    B *unk6C;
};

extern "C" s32 func_005F6698(Obj *arg0) {
    return arg0->unk6C->unk80->unk4->unk80;
}
