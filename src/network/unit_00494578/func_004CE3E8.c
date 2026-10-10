typedef int s32;
void func_004CB7B0(void *a, s32 b);
s32 func_004CE478(void *a, s32 b);
void func_004CE508(void *a, s32 b, s32 c);
void func_005C1628(void *a);
extern char D_00689478[];
void func_004CE3E8(char *arg0, s32 arg1) {
    s32 temp_v0;

    *(char **)(arg0 + 0x78) = D_00689478;
    temp_v0 = func_004CE478(arg0, 1);
    if (temp_v0 > 0) {
        func_004CE508(arg0, 1, temp_v0 | 0x08000000);
    }
    func_004CB7B0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
