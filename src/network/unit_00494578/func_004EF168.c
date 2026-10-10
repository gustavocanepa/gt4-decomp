typedef int s32;
void func_004EF9F0(char *a, s32 b);
void func_004EF9C8(char *a, s32 b);
s32 func_004EF168(char *arg0) {
    if (*(s32 *)arg0 == 0) return 0;
    func_004EF9F0(arg0, 0);
    func_004EF9C8(arg0, 0);
    *(s32 *)(arg0 + 0x98) = 0;
    return 1;
}
