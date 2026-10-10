void func_001C9630(signed char *d, unsigned char *a, unsigned char *b, int w0, int w3, int v0, int v3) {
    int lo = b[0] * v0 + a[0] * w0;
    int hi = b[3] * v3 + a[3] * w3;
    *d = (lo + hi) >> 16;
}
