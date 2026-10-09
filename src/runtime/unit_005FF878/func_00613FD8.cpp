typedef unsigned int u32;

extern "C" void func_00614028();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62E0;

extern int D_008A1BC0;

extern "C" void *func_00613FD8(void) {
    if (D_008A1BC0 == 0) {
        func_00614028();
        func_005BFB68(&D_008A1BC0, ((char *)"Q235_GLOBAL_$N$stdio_vsprintf.cxxiYcX7w11PrintTarget"), &D_006D62E0);
    }
    return &D_008A1BC0;
}
