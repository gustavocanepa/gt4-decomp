typedef unsigned int u32;

extern "C" void func_0060AC48();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0290[];
extern int D_0088FF38;

static int D_0088D9A0;

extern "C" void *func_0060B310(void) {
    if (D_0088D9A0 == 0) {
        func_0060AC48();
        func_005BFB68(&D_0088D9A0, D_006B0290, &D_0088FF38);
    }
    return &D_0088D9A0;
}
