typedef signed char s8;

extern "C" void func_00353570(char *arg0) {
    s8 *p = (s8 *)(arg0 + 0xF830);
    int i;

    for (i = 0; i < 4; i++) {
        if (*p == 0) {
            *p = 0x14;
        }
        p++;
    }
}
