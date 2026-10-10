typedef int s32;
s32 func_0057CA80(void **arg0) {
    s32 n = 0;
    void **p = (void **)*arg0;
    while (p != 0) {
        p = (void **)p[2];
        n++;
    }
    return n;
}
