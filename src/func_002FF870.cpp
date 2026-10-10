typedef int s32;
typedef unsigned char u8;

extern "C" void func_002FF7E8(void *stream, u8 *buf, s32 n);

extern "C" s32 func_002FF870(void *stream) {
    u8 b[4];
    func_002FF7E8(stream, b, 4);
    return b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24);
}
