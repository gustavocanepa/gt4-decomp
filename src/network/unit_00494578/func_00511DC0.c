typedef int s32;
s32 func_00511DC0(char *arg0, s32 *arg1) {
    s32 *p;
    if (arg1 == 0) return 1;
    p = *(s32 **)(arg0 + 0x24);
    if (p == 0) return 3;
    *arg1 = *p;
    return 0;
}
