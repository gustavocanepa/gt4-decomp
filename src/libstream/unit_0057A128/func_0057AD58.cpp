typedef unsigned long u64;
struct BitReader { int m0; unsigned char *p; unsigned char cur; int left; };


extern "C" u64 func_0057AD58(BitReader *br, int n)
{
    unsigned char *p = br->p;
    u64 cur = br->cur;
    int left = br->left;
    u64 r = 0;
    while (n) {
        if (left == 0) { cur = *p++; left = 8; }
        int k = left < n ? left : n;
        r = (r << k) | (cur >> (8 - k));
        cur = (cur << k) & 0xFF;
        n -= k;
        left -= k;
    }
    br->p = p;
    br->cur = cur;
    br->left = left;
    return r;
}
