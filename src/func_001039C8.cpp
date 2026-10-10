extern "C" void func_00103330(unsigned char *dst, unsigned char *src);
extern "C" void func_00103640(unsigned char *dst, unsigned char *src);

extern "C" void func_001039C8(unsigned char *dst, unsigned char *src)
{
    for (int i = 0; i < 8; i++) {
        func_00103330(dst + 0x100, src);
        func_00103640(dst + 0x101, src + 0x780);
        func_00103640(dst + 0x300, src + 0xF00);
        func_00103330(dst + 0x301, src + 0x1680);
        src += 0x1E00;
        dst += 0x400;
    }
}
