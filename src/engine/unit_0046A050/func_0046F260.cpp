extern "C" void func_0046F198(void *s, int nbits, unsigned int v);

extern "C" void func_0046F260(void *s, int nbits, unsigned int v)
{
    if (nbits > 8) {
        func_0046F198(s, nbits - 8, v >> 8);
        nbits = 8;
    }
    func_0046F198(s, nbits, v);
}
