typedef unsigned int u32;

extern "C" void func_00612FF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8BD8[];
extern int D_006D62B8;

extern int D_008A1AA0;

extern "C" void *func_00611FC8(void) {
    if (D_008A1AA0 == 0) {
        func_00612FF0();
        func_005BFB68(&D_008A1AA0, D_006C8BD8, &D_006D62B8);
    }
    return &D_008A1AA0;
}
