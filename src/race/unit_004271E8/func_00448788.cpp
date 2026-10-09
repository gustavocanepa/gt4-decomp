struct D_LocalBuf {
    char pad[0xF];
    unsigned char bF;
    unsigned char b10;
};

extern "C" int func_00448A58(void *arg0, D_LocalBuf *arg1);

extern "C" int func_00448788(void *arg0, int *arg1, int *arg2) {
    D_LocalBuf buf;
    if (func_00448A58(arg0, &buf)) {
        *arg1 = buf.bF;
        *arg2 = buf.b10;
        return 1;
    }
    return 0;
}
