typedef unsigned int u32;

extern "C" void func_005C24C8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BBF8[];
extern int D_006D5E08;

extern int D_0088D960;

extern "C" void *func_005C1F98(void) {
    if (D_0088D960 == 0) {
        func_005C24C8();
        func_005BFB68(&D_0088D960, D_0068BBF8, &D_006D5E08);
    }
    return &D_0088D960;
}
