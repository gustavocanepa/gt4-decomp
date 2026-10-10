extern char D_00873F00[];
extern int D_00654AC0[];

struct Copy60 { int w[15]; };

extern "C" int func_005616E8(int a, int b);
extern "C" void func_00561818(void *);
extern "C" void func_00561770(void *);
extern "C" void func_005617A8(void *);
extern "C" int func_005B19B0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

extern "C" int func_00561820(int a0, int a1, int a2) {
    if (a2 == 0)
        return 0x80000004;
    if (func_005616E8(1, 0) != 0)
        return 0x80000008;
    D_00654AC0[2] = a0;
    D_00654AC0[24] = a1;
    D_00654AC0[144] = a2;
    func_005B19B0(D_00873F00, 6, 1, D_00654AC0, 0x240, D_00654AC0, 0x240, (void *)func_00561770, D_00654AC0);
    return 0;
}
