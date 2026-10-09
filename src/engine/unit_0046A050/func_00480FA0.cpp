typedef int s32;

struct S00480F78 {
    char pad0[8];
    s32 unk8;
};

extern "C" void func_00480F78(struct S00480F78 *arg0);

extern "C" void func_00480FA0(struct S00480F78 *arg0, s32 arg1) {
    s32 count = arg1;
    if (count > 0) {
        s32 i = count;
        do {
            i--;
            func_00480F78(arg0);
        } while (i != 0);
    }
}
