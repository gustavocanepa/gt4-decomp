typedef int s32;

struct S00293B10 {
    char pad0[0xB4];
    s32 unkB4;
};

extern "C" void func_00293B10(struct S00293B10 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkB4;
    v = v & ~0x2;
    v = v | (temp << 1);
    arg0->unkB4 = v;
}
