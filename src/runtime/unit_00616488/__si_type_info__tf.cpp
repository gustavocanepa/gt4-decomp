typedef unsigned int u32;

extern "C" void __user_type_info__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006D3048[];
extern int D_008A20A0;

extern int D_008A20B0;

extern "C" void *__si_type_info__tf(void) {
    if (D_008A20B0 == 0) {
        __user_type_info__tf();
        func_005BFB68(&D_008A20B0, D_006D3048, &D_008A20A0);
    }
    return &D_008A20B0;
}
