typedef int s32;

struct S005E5BA0 {
    char pad[0xB4];
    s32 unkB4;
};

extern "C" void func_005E5BA0(struct S005E5BA0 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkB4;
    v = v & ~0x80;
    v = v | (temp << 7);
    arg0->unkB4 = v;
}
