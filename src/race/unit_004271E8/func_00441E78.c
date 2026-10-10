typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
void func_00441E78(char *arg0, char *arg1, char *arg2) {
    s32 i;
    u16 *dst = (u16 *)(arg1 + 0x138);
    u16 *src = (u16 *)(arg0 + 0x110);
    *(u16 *)(arg1 + 0x152) = *(u16 *)(arg2 + 0x1E);
    *(u8 *)(arg1 + 0x154) = *(u8 *)(arg2 + 0x29);
    for (i = 0; i < 12; i++) *dst++ = *src++;
    *(u16 *)(arg1 + 0x150) = *(u16 *)(arg0 + 0x128);
    *(u8 *)(arg1 + 0x157) = *(u8 *)(arg0 + 0x12A);
    *(u8 *)(arg1 + 0x155) = *(u8 *)(arg2 + 0x24);
    *(u8 *)(arg1 + 0x156) = 0;
    *(u8 *)(arg1 + 0x158) = *(u8 *)(arg2 + 0x23);
}
