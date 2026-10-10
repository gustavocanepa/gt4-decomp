extern unsigned short D_006CC790[];

extern "C" void func_001CBD18(char *dst, const char *src) {
    char c;
    while ((c = *src++) != 0) {
        int w = D_006CC790[c];
        dst[1] = w;
        dst[0] = w >> 8;
        dst += 2;
    }
    *dst = 0;
}
