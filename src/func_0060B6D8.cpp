typedef unsigned int u32;

extern "C" void func_0060B3B8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0320[];
extern int D_0089FFE0;

extern int D_008A0010;

extern "C" void *func_0060B6D8(void) {
    if (D_008A0010 == 0) {
        func_0060B3B8();
        func_005BFB68(&D_008A0010, D_006B0320, &D_0089FFE0);
    }
    return &D_008A0010;
}
