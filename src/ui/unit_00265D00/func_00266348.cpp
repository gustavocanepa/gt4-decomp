typedef int s32;

struct S00266348 {
    char pad0[0x9C];
    s32 unk9C;
};

extern "C" void func_00266348(struct S00266348 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x4;
    v = v | (temp << 2);
    arg0->unk9C = v;
}
