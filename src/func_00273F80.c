static inline int plzcw(int x) { int r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(x)); return r; }

extern unsigned int D_00618E4C;

float func_00273F80(void)
{
    unsigned int n = D_00618E4C;
    int shift = (plzcw(n - 1) & 0x1F) ^ 0x1F;
    return (float)n / (float)(unsigned int)(1 << shift);
}
