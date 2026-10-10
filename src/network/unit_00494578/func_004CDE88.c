typedef int s32;
void func_004CB7B0(void *a, s32 b);
s32 func_004CDF10(void *a, s32 b);
void func_004CDF98(void *a, s32 b, s32 c);
void func_005C1628(void *a);
extern char D_006894C8[];
void func_004CDE88(char *arg0, s32 arg1) {
    s32 temp_v0;

    *(char **)(arg0 + 0x78) = D_006894C8;
    temp_v0 = func_004CDF10(arg0, 1);
    if (temp_v0 > 0) {
        func_004CDF98(arg0, 1, temp_v0 | 0x8000);
    }
    func_004CB7B0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
