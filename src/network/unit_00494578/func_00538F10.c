int func_00538F10(signed char *p, short v) {
    int r = 2;
    if (p != 0) {
        r = 0;
        p[0] = v;
        p[1] = v >> 8;
    }
    return r;
}
