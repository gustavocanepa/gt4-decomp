typedef unsigned int u32;

extern "C" void func_0060D4E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D61C8;

extern int D_008A0090;

extern "C" void *func_0060D678(void) {
    if (D_008A0090 == 0) {
        func_0060D4E0();
        func_005BFB68(&D_008A0090, ((char *)"Q26PDISTD5Fat16"), &D_006D61C8);
    }
    return &D_008A0090;
}
