typedef int s32;
s32 func_003EF298(char *arg0) {
    s32 lim = *(s32 *)(arg0 + 0x2F8);
    char *p = arg0 + 0x480;
    s32 i = 1;
    do {
        if (*(s32 *)p >= lim) return 0;
        p += 0x188;
        i++;
    } while (i < 6);
    return 1;
}
