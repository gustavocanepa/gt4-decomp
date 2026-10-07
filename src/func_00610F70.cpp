typedef unsigned int u32;

extern "C" void func_00610DE8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8740[];
extern int D_006D6248;

static int D_0088D9A0;

extern "C" void *func_00610F70(void) {
    if (D_0088D9A0 == 0) {
        func_00610DE8();
        func_005BFB68(&D_0088D9A0, D_006C8740, &D_006D6248);
    }
    return &D_0088D9A0;
}
