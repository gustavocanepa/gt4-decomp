typedef int s32;

extern "C" s32 D_0064C3C4;
extern "C" char D_0086CA40[];
extern "C" void func_00578148(void *p, s32 tag);
extern "C" void func_005477E8(void);
extern "C" void func_00551218(void);

extern "C" void func_00547D88(void) {
    if (D_0064C3C4 == 0) {
        D_0064C3C4 = 1;
        func_00578148(D_0086CA40, 0x5042474D);
        func_005477E8();
        func_00551218();
    }
}
