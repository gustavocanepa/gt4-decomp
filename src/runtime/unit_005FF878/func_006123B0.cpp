typedef unsigned int u32;

extern "C" void func_00612518();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8C38[];
extern int D_006D6268;

extern int D_008A1AB0;

extern "C" void *func_006123B0(void) {
    if (D_008A1AB0 == 0) {
        func_00612518();
        func_005BFB68(&D_008A1AB0, D_006C8C38, &D_006D6268);
    }
    return &D_008A1AB0;
}
