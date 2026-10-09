typedef unsigned int u32;

extern "C" void func_00602340();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6730[];
extern int D_006D60A0;

extern int D_0088FDE0;

extern "C" void *func_00603170(void) {
    if (D_0088FDE0 == 0) {
        func_00602340();
        func_005BFB68(&D_0088FDE0, D_006A6730, &D_006D60A0);
    }
    return &D_0088FDE0;
}
