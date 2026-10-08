typedef int s32;

struct Obj {
    char pad[0xC8];
    s32 unkC8;
};

extern "C" void func_005E63F8(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkC8;
    v = v & ~0x2;
    v = v | (temp << 1);
    arg0->unkC8 = v;
}
