typedef unsigned int u32;

extern "C" void func_0060B0C8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A7CB8[];
extern int D_0088FF78;

extern int D_0088FE00;

extern "C" void *FileInstrumentStream__tf(void) {
    if (D_0088FE00 == 0) {
        func_0060B0C8();
        func_005BFB68(&D_0088FE00, D_006A7CB8, &D_0088FF78);
    }
    return &D_0088FE00;
}
