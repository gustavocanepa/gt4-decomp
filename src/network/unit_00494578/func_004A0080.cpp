/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Resets the state block at 0x3E0 (0x680 bytes) and writes its defaults. The word at 0x4A8 is
   cleared as an int and read back as the float zero used for the later fields. */
#define F(off) (*(float *)((char *)self + (off)))
#define I(off) (*(int *)((char *)self + (off)))
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_004A5DA0(float);
extern "C" void func_004A0080(char *self) {
    func_005A48D8(self + 0x3E0, 0, 0x680);
    F(0x478) = -1.0f;
    I(0x4A8) = 0;
    float zero = F(0x4A8);
    F(0x49C) = 180.0f;
    F(0x3FC) = 1.0f;
    F(0x400) = 1.0f;
    F(0x404) = 1.0f;
    F(0x408) = 1.0f;
    F(0x40C) = 1.0f;
    F(0x420) = 1.0f;
    F(0x424) = 1.0f;
    F(0x428) = 1.0f;
    F(0x42C) = 1.0f;
    F(0x448) = 1.0f;
    F(0x4A4) = 1.0f;
    F(0x4AC) = 1.0f;
    int v = func_004A5DA0(zero);
    I(0x3EC) = v;
    F(0xAE0) = 0x1.999998p-3f;
    F(0xAEC) = 1.0f;
    F(0xAE4) = 0x1.999998p-3f;
    F(0xAE8) = 0x1.999998p-3f;
    *(short *)(self + 0x48) = 7;
    F(0xAB0) = zero;
    F(0xAB4) = zero;
    F(0xAB8) = zero;
    F(0xABC) = 1.0f;
    *(char *)(self + 2) = 2;
}
