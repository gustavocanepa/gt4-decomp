typedef int s32;
typedef unsigned char u8;

extern "C" void func_0047D178(s32 arg0, char *arg1, char *arg2) {
    s32 temp_a0 = arg0 + 0xC;
    char *src = arg2 + temp_a0;
    char *dst = arg1 + temp_a0;
    *(u8 *)(dst + 0x10) = *(u8 *)(src + 0x10);
}
