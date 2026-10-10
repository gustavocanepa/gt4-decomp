typedef unsigned short u16;

extern const u16 D_006B0500[];
extern const u16 D_006B0550[];

static inline void ustrcpy(u16 *d, const u16 *s) {
    while ((*d++ = *s++) != 0)
        ;
}

extern "C" int func_004B8F60(u16 *dst, int c) {
    const u16 *src = 0;
    if (c == 'n' || c == 'N')
        src = D_006B0500;
    else if (c == 'k' || c == 'K')
        src = D_006B0550;
    if (src) {
        ustrcpy(dst, src);
        return 1;
    }
    *dst = 0;
    return 0;
}
