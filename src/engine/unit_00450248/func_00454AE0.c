char *func_00454AE0(unsigned char *p) {
    char *r;
    if (*p == 0xFF) r = (char *)p + 8;
    else r = (char *)p + *p * 4 + 4;
    return r;
}
