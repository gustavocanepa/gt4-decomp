typedef int s32;

struct S { char pad0[4]; s32 f4; s32 f8; };

extern s32 func_005A3FC8();

s32 func_005A8240(void *arg0, struct S *arg1) {
    s32 temp_v0;

    if (arg1->f8 == 0) {
        arg1->f4 = 0;
        return 0;
    }
    temp_v0 = func_005A3FC8();
    arg1->f8 = 0;
    arg1->f4 = 0;
    return temp_v0;
}
