typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
s32 func_00539128(u8 *arg0, u16 *arg1) {
    if (arg0 == 0) return 2;
    if (arg1 == 0) return 2;
    *arg1 = arg0[0] << 8;
    *arg1 |= arg0[1];
    return 0;
}
