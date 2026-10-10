int func_001C6DC8(char *p) {
    unsigned char *q = (unsigned char *)(p + 0x900);
    int r = 1;
    int i;
    for (i = 1; i >= 0; i--) {
        if (*q) r = 0;
        q += 0x2B8;
    }
    return r;
}
