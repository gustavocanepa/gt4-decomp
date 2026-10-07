typedef unsigned int u32;

extern "C" void func_005CB130();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697CF0[];
extern int D_006D5E60;

extern int D_0088E120;

extern "C" void *func_005DA140(void) {
    if (D_0088E120 == 0) {
        func_005CB130();
        func_005BFB68(&D_0088E120, D_00697CF0, &D_006D5E60);
    }
    return &D_0088E120;
}
