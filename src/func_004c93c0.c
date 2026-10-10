int func_004C93C0(unsigned char *p) {
    int n = 0;
    while (*p != 0) {
        p += (*p & 0x80) ? 2 : 1;
        n++;
    }
    return n;
}
