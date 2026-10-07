typedef unsigned int u32;

extern "C" void func_005C21E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BF70[];
extern int D_0088D9E0;

extern int D_0088DA00;

extern "C" void *func_005C2238(void) {
    if (D_0088DA00 == 0) {
        func_005C21E0();
        func_005BFB68(&D_0088DA00, D_0068BF70, &D_0088D9E0);
    }
    return &D_0088DA00;
}
