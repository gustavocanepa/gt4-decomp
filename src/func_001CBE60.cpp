extern "C" char *D_00618D10;
static inline char encode(int v) { return D_00618D10[v]; }
extern "C" void func_001CBE60(char *dst, long bits, int n) {
    int i;
    for (i = 0; i < n; i++) {
        *dst++ = encode(bits & 0x3F);
        bits >>= 6;
    }
    *dst = 0;
}
