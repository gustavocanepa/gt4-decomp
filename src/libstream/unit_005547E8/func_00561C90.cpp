extern char D_00873F00[];
extern int D_00654AC0[];

extern "C" int func_005616E8(int a, int b);
extern "C" void func_00561818(void *);
extern "C" int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

extern "C" int func_00561C90(int a0) {
    if (func_005616E8(1, 0) != 0)
        return 0x80000008;
    D_00654AC0[6] = a0;
    func_005B19B0(D_00873F00, 0x9, 1, D_00654AC0, 0x240, D_00654AC0, 0x240, (void *)func_00561818, D_00654AC0);
    return 0;
}
