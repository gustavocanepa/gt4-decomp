typedef int s32;
typedef unsigned short u16;

extern "C" s32 func_0035BE10(char *arg0base) {
    u16 *p = (u16 *)(arg0base + 0x5BC);
    u16 flags = *p;

    if ((flags & 0x20) == 0) {
        return 0;
    }
    *p = flags ^ 0x20;
    return 1;
}
