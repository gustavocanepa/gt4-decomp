typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern s32 func_00538EE8(u8 *arg0, u8 *arg1);
s32 func_00521E58(int a0, u8 *buf, u32 lim, u32 *pos) {
    u8 c = 0;
    int n;
    u32 p;
    s32 r;
    do {
        func_00538EE8(buf + *pos, &c);
        if (c == 0)
            goto tail;
        n = c;
        *pos += n + 1;
    } while (!(lim < *pos));
    return 0xC35A;
tail:
    p = *pos + 5;
    do { r = 0xC35A; if (!(lim < p)) r = 0; *pos = p; } while (0);
    return r;
}
