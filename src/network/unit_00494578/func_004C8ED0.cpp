typedef int s32;
typedef unsigned short u16;

extern "C" s32 func_004C8ED0(u16 *arg0) {
    u16 *p = arg0 + 1;
    s32 count = 0;

    if (*arg0 != 0) {
        u16 v;
        do {
            v = *p;
            p += 1;
            count += 1;
        } while (v != 0);
    }

    return count;
}
