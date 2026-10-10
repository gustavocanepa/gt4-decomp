typedef unsigned int u32;

extern "C" void func_005C2050();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088D9A0;

extern int D_0088D980;

extern "C" void *func_005C20A0(void) {
    if (D_0088D980 == 0) {
        func_005C2050();
        func_005BFB68(&D_0088D980, ((char *)"Q212GranTurismo417GameObjectManager"), &D_0088D9A0);
    }
    return &D_0088D980;
}
