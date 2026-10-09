typedef unsigned char u8;
typedef int s32;

extern "C" void func_002FF7E8(void *arg0, u8 *arg1, s32 arg2);

extern "C" s32 func_002FF840(void *arg0) {
    u8 buf[2];
    func_002FF7E8(arg0, buf, 2);
    return buf[0] | (buf[1] << 8);
}
