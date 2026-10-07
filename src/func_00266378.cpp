typedef int s32;

struct S00266378 {
    char pad0[0x9C];
    s32 unk9C;
};

extern "C" void func_00266378(struct S00266378 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x8;
    v = v | (temp << 3);
    arg0->unk9C = v;
}
