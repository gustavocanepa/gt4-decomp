typedef unsigned int u32;

extern "C" void func_005C2188();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BF40[];
extern int D_0088D9D0;

extern int D_0088D9E0;

extern "C" void *func_005C21E0(void) {
    if (D_0088D9E0 == 0) {
        func_005C2188();
        func_005BFB68(&D_0088D9E0, D_0068BF40, &D_0088D9D0);
    }
    return &D_0088D9E0;
}
