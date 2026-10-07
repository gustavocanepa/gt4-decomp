typedef unsigned int u32;

extern "C" void func_005FBD90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4510[];
extern int D_006D6020;

extern int D_0088FA80;

extern "C" void *func_005FF4A0(void) {
    if (D_0088FA80 == 0) {
        func_005FBD90();
        func_005BFB68(&D_0088FA80, D_006A4510, &D_006D6020);
    }
    return &D_0088FA80;
}
