typedef int s32;
typedef unsigned char u8;
s32 func_004C9368(u8 *arg0, s32 arg1) {
    s32 n = 0;
    while (*arg0 != 0 && arg1 > 0) {
        if (*arg0 & 0x80) {
            arg0 += 2;
            arg1 -= 2;
        } else {
            arg0 += 1;
            arg1 -= 1;
        }
        n++;
    }
    return n;
}
