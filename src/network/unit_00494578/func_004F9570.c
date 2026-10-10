void func_004F9570(char *a) {
    int *p = (int *)(a + 0xCD4);
    int m = -1;
    int i;
    for (i = 2; i >= 0; i--) { *p = m; p--; }
}
