typedef unsigned int u32;

extern "C" void func_00610DE8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6248;

extern int D_008A1A70;

extern "C" void *func_00610F70(void) {
    if (D_008A1A70 == 0) {
        func_00610DE8();
        func_005BFB68(&D_008A1A70, ((char *)"Q212PlayStation27hdx1735"), &D_006D6248);
    }
    return &D_008A1A70;
}
