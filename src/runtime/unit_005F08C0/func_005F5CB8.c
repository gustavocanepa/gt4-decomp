void func_005F5CB8(char *a) {
    unsigned long long x = *(unsigned long long *)(a + 0x260);
    x &= 0xFFFF00FFFFFFFFFFULL;
    x |= 0x10000000000ULL;
    *(unsigned long long *)(a + 0x260) = x;
}
