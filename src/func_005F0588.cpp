typedef unsigned int u32;

extern "C" void func_005F1A58();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E500[];
extern int D_006D5F40;

static int D_0088D9A0;

extern "C" void *func_005F0588(void) {
    if (D_0088D9A0 == 0) {
        func_005F1A58();
        func_005BFB68(&D_0088D9A0, D_0069E500, &D_006D5F40);
    }
    return &D_0088D9A0;
}
