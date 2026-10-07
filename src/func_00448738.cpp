struct D_LocalBuf {
    char pad[0xF];
    unsigned char bF;
    unsigned char b10;
};

extern "C" int func_004489B0(void *arg0, D_LocalBuf *arg1);

extern "C" int func_00448738(void *arg0, int *arg1, int *arg2) {
    D_LocalBuf buf;
    if (func_004489B0(arg0, &buf)) {
        *arg1 = buf.bF;
        *arg2 = buf.b10;
        return 1;
    }
    return 0;
}
