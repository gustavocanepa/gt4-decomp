typedef unsigned int u32;

extern "C" void func_00616370();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006D31A0[];
extern int D_006D6300;

extern int D_008A2100;

extern "C" void *func_00616D08(void) {
    if (D_008A2100 == 0) {
        func_00616370();
        func_005BFB68(&D_008A2100, D_006D31A0, &D_006D6300);
    }
    return &D_008A2100;
}
