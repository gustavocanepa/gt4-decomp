typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void func_005F8E98(struct Obj *arg0, u8 arg1) {
    arg0->unk18 = (arg0->unk18 & ~0xFF) | arg1;
}
