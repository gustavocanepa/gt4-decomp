extern char D_00873F00[];
extern int D_00654AC0[];

struct Copy60 { int w[15]; };

extern "C" int func_005616E8(int a, int b);
extern "C" void func_00561818(void *);
extern "C" void func_00561770(void *);
extern "C" void func_005617A8(void *);
extern "C" int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

extern "C" int func_005618D0(int n, int *p1, int *p2, int a3) {
    if (n < 1 || n > 4)
        return 0x80000004;
    if (p1 == 0)
        return 0x80000004;
    if (p2 == 0)
        return 0x80000004;
    if (a3 == 0)
        return 0x80000004;
    if (func_005616E8(1, 0) != 0)
        return 0x80000008;
    for (int i = 0; i < n; i++) {
        D_00654AC0[2 + i] = p1[i];
        D_00654AC0[24 + i] = p2[i];
    }
    D_00654AC0[23] = n;
    D_00654AC0[144] = a3;
    func_005B19B0(D_00873F00, 0xE, 1, D_00654AC0, 0x240, D_00654AC0, 0x240, (void *)func_005617A8, D_00654AC0);
    return 0;
}
