typedef int s32;
typedef unsigned short u16;
s32 func_00523E28(char *arg0, u16 *arg1) {
    if (arg1 == 0) return 2;
    *arg1 = 0;
    if (arg0 == 0) return 2;
    *arg1 = *(u16 *)(arg0 + 0xB8);
    return 0;
}
