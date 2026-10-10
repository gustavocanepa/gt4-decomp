typedef unsigned u32;
void func_004904E8(char *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 a = arg1 & 0xFF;
    u32 b = arg2 & 0xFF;
    u32 c = arg3 & 0xFF;
    u32 x = (arg4 << 24) | a;
    u32 y = (b << 8) | (c << 16);
    *(u32 *)(arg0 + 0x44) = x | y;
}
