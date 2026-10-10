void func_004F9538(char *a) {
    int *p = (int *)(a + 0xCC8);
    int m = -1;
    int i;
    for (i = 2; i >= 0; i--) { *p = m; p--; }
}
