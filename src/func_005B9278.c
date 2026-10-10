/* compiler: ee-gcc2.9-991111 */
extern int D_006D2918[12];

int func_005B9278(int (*fn)(int)) {
    unsigned int i;
    int r;
    for (i = 0; i < 12; i++) {
        r = fn(D_006D2918[i]);
        if (r < 0)
            return r;
    }
    return 0;
}
