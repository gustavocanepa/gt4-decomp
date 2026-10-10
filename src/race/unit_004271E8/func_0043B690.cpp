struct Set { int m0; unsigned int bits[8]; };
extern "C" void func_0043B608(Set *self, int a, unsigned int bit);

extern "C" void func_0043B690(Set *self, int a, unsigned int bit)
{
    func_0043B608(self, a, bit);
    self->bits[bit >> 5] |= 1 << (bit & 31);
}
