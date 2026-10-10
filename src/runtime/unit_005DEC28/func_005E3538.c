static inline int plzcw(int x) { int r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(x)); return r; }

float func_005E3538(int unused, unsigned int n)
{
    int shift = (plzcw(n - 1) & 0x1F) ^ 0x1F;
    return (float)n / (float)(unsigned int)(1 << shift);
}
