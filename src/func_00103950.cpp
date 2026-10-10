struct Block { char d[0x780]; };
extern "C" void func_00103330(unsigned char *dst, Block *src);
extern "C" void func_00103640(unsigned char *dst, Block *src);

extern "C" void func_00103950(unsigned char *dst, Block *src)
{
    for (int i = 0; i < 8; i++) {
        func_00103330(dst, src);
        func_00103640(dst + 1, src + 1);
        func_00103640(dst + 0x200, src + 2);
        func_00103330(dst + 0x201, src + 3);
        dst += 0x400;
        src += 4;
    }
}
