typedef unsigned char u8;
typedef int s32;

extern "C" void HIO__read(void *arg0, u8 *arg1, s32 arg2);

extern "C" s32 func_002FF840(void *arg0) {
    u8 buf[2];
    HIO__read(arg0, buf, 2);
    return buf[0] | (buf[1] << 8);
}
