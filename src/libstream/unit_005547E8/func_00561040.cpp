extern char D_00873F00[];
extern int D_00873F40[];

struct Copy60 { int w[15]; };

extern "C" int func_005616E8(int a, int b);
extern "C" int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

extern "C" int func_00561040(int a0, int *inout, Copy60 *in) {
    if (inout == 0)
        return 0x80000004;
    if (in == 0)
        return 0x80000004;
    func_005616E8(0, 0);
    D_00873F40[2] = a0;
    D_00873F40[6] = *inout;
    *(Copy60 *)((char *)D_00873F40 + 0x70) = *in;
    if (func_005B19B0(D_00873F00, 7, 0, D_00873F40, 0x240, D_00873F40, 0x240, 0, 0) == 0) {
        *inout = D_00873F40[6];
        return D_00873F40[0];
    }
    return 0x80000000;
}
