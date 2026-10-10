extern char D_00873F00[];
extern int D_00873F40[];

extern "C" int func_005616E8(int a, int b);
extern "C" int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

extern "C" int func_00560CA0(int a0, int a1, int *out) {
    if (out == 0)
        return 0x80000004;
    func_005616E8(0, 0);
    D_00873F40[2] = a0;
    D_00873F40[22] = a1;
    if (func_005B19B0(D_00873F00, 4, 0, D_00873F40, 0x240, D_00873F40, 0x240, 0, 0) == 0) {
        *out = D_00873F40[23];
        return D_00873F40[0];
    }
    return 0x80000000;
}
