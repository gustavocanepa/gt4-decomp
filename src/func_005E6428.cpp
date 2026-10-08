typedef int s32;

struct S005E6428 {
    char pad[0xC8];
    s32 unkC8;
};

extern "C" void func_005E6428(struct S005E6428 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkC8;
    v = v & ~4;
    v = v | (temp << 2);
    arg0->unkC8 = v;
}
