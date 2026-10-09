typedef int s32;

struct S002663D8 {
    char pad0[0x9C];
    s32 unk9C;
};

extern "C" void func_002663D8(struct S002663D8 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x20;
    v = v | (temp << 5);
    arg0->unk9C = v;
}
