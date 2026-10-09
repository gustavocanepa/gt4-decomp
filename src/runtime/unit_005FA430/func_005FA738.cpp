typedef int s32;
typedef unsigned char u8;

struct Obj {
    s32 unk0;
};

extern "C" void func_005FA738(Obj *arg0, u8 arg1) {
    arg0->unk0 = (arg0->unk0 & ~0xFF) | arg1;
}
