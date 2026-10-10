extern char D_00873F00[];
extern int D_00873F40[];

extern "C" int func_005616E8(int a, int b);
extern "C" int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

extern "C" int func_005613E0(int a0) {
    func_005616E8(0, 0);
    D_00873F40[6] = a0;
    if (func_005B19B0(D_00873F00, 0x9, 0, D_00873F40, 0x240, D_00873F40, 0x240, 0, 0) == 0)
        return D_00873F40[0];
    return 0x80000000;
}
