typedef int s32;

struct S005E63C8 {
    char pad[0xC8];
    s32 unkC8;
};

extern "C" void func_005E63C8(struct S005E63C8 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkC8;
    v = v & ~1;
    v = v | temp;
    arg0->unkC8 = v;
}
