typedef unsigned int u32;

extern "C" void func_005DBDA8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698A90[];
extern int D_006D5EE8;

static int D_0088D9A0;

extern "C" void *func_005DBCC0(void) {
    if (D_0088D9A0 == 0) {
        func_005DBDA8();
        func_005BFB68(&D_0088D9A0, D_00698A90, &D_006D5EE8);
    }
    return &D_0088D9A0;
}
