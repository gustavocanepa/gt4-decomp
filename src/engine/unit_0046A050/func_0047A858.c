typedef int s32;
s32 func_004772A0(s32 *a);
s32 func_0047A858(char *arg0) {
    s32 *p = (s32 *)(arg0 + 0x14);
    if ((*p ^ 7) == 0) return func_004772A0(p) + 4;
    return 0;
}
