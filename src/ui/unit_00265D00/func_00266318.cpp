typedef int s32;

struct S00266318 {
    char pad0[0x9C];
    s32 unk9C;
};

extern "C" void func_00266318(struct S00266318 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x2;
    v = v | (temp << 1);
    arg0->unk9C = v;
}
