typedef int s32;
typedef unsigned short u16;
void func_00458238(s32 *arg0) {
    s32 *p;
    s32 n;
    s32 d;
    s32 *old = (s32 *)arg0[1];
    if (arg0 == old) return;
    d = (char *)arg0 - (char *)old;
    n = *(u16 *)((char *)arg0 + 0x10) * *(u16 *)((char *)arg0 + 0x12);
    arg0[1] = (s32)arg0;
    if (n > 0) {
        p = arg0 + 8;
        do {
            if (*p != 0) *p = *p + d;
            n -= 1;
            p += 1;
        } while (n != 0);
    }
}
