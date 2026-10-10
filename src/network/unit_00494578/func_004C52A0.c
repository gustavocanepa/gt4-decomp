typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned u32;
s32 func_004C9330(u8 *);
void func_004C52A0(s16 *arg0, u8 *arg1, u32 arg2) {
    u8 *p;
    if (arg2 >= (u32)((func_004C9330(arg1) * 2) + 2)) {
        p = arg1;
        if (*p != 0) {
            do {
                u8 c = *p;
                p++;
                *arg0 = (c & 0xBF) | 0xA3B0;
                arg0++;
            } while (*p != 0);
        }
    }
    *arg0 = 0;
}
