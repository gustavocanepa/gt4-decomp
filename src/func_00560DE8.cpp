extern char D_00873F00[];
extern int D_00873F40[];

struct Copy24 { char b[0x18]; };

extern "C" int func_005616E8(int a, int b);
extern "C" int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

extern "C" int func_00560DE8(int a0, int a1, Copy24 *out) {
    if (out == 0)
        return 0x80000004;
    func_005616E8(0, 0);
    D_00873F40[2] = a0;
    D_00873F40[24] = a1;
    if (func_005B19B0(D_00873F00, 6, 0, D_00873F40, 0x240, D_00873F40, 0x240, 0, 0) == 0) {
        *out = *(Copy24 *)((char *)D_00873F40 + 0x70);
        return D_00873F40[0];
    }
    return 0x80000000;
}
