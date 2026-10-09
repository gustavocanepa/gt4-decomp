typedef unsigned int u32;

extern "C" void func_005C20A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BBB8[];
extern int D_0088D980;

extern int D_0088D970;

extern "C" void *func_005C1E90(void) {
    if (D_0088D970 == 0) {
        func_005C20A0();
        func_005BFB68(&D_0088D970, D_0068BBB8, &D_0088D980);
    }
    return &D_0088D970;
}
