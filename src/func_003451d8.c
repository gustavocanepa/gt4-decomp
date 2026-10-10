int func_003451D8(char *t) {
    char *q = t + 0x104;
    int s;
    if (*(unsigned char *)(q + 0x441) != 0) return 0;
    s = *(signed char *)(q + 0x466);
    if (s == 0) return 1;
    if (s == 4) return 1;
    return s == 1;
}
