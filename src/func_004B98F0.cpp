typedef int s32;
typedef unsigned short u16;

extern "C" s32 func_004B98F0(const u16 *s) {
    s32 n = 0;
    while (*s != 0) {
        u16 c = *s++;
        s32 k = 3;
        k -= c < 0x800;
        k -= c < 0x80;
        n += k;
    }
    return n;
}
