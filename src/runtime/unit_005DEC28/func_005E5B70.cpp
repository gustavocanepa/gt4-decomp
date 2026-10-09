typedef int s32;

struct S005E5B70 {
    char pad[0xB4];
    s32 unkB4;
};

extern "C" void func_005E5B70(struct S005E5B70 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkB4;
    v = v & ~0x40;
    v = v | (temp << 6);
    arg0->unkB4 = v;
}
