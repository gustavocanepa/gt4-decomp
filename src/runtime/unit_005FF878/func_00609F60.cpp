typedef unsigned int u32;

extern "C" void func_00607408();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6170;

extern int D_0088FEC0;

extern "C" void *func_00609F60(void) {
    if (D_0088FEC0 == 0) {
        func_00607408();
        func_005BFB68(&D_0088FEC0, ((char *)"Q26strobe14ButtonInstance"), &D_006D6170);
    }
    return &D_0088FEC0;
}
