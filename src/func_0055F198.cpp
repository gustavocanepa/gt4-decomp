typedef int s32;
typedef unsigned short u16;

extern "C" void *func_005A48D8(void *, s32, s32);
extern "C" void *func_005A4724(void *, const void *, s32);

extern "C" void func_0055F198(void *dst, u16 *src) {
    func_005A48D8(dst, 0, 0x24);
    func_005A4724(dst, src, *src);
}
