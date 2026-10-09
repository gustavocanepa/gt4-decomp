typedef int s32;
typedef short s16;

struct A {
    char pad[0xA0];
    s32 unkA0;
};

struct B {
    char pad[6];
    s16 unk6;
};

struct Obj {
    A *unk0;
    B *unk4;
};

extern "C" s32 func_00484D20(Obj *arg0) {
    return arg0->unk0->unkA0 + (arg0->unk4->unk6 * 0x14);
}
