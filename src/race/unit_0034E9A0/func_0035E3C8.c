typedef int s32;
typedef unsigned u32;
s32 func_0035E3C8(char *arg0, u32 arg1) {
    char *p = arg0 + 0x104;
    if (arg1 >= *(u32 *)(p + 0x618)) return 0;
    *(u32 *)(p + 0x618) = arg1;
    return 1;
}
