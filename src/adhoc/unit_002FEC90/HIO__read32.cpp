typedef int s32;
typedef unsigned char u8;

extern "C" void HIO__read(void *stream, u8 *buf, s32 n);

extern "C" s32 HIO__read32(void *stream) {
    u8 b[4];
    HIO__read(stream, b, 4);
    return b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24);
}
