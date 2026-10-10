typedef unsigned int u32;

struct BitSet {
    u32 unk0;
    u32 bits[1];
};

extern "C" void func_0043B608(BitSet *self, int a, u32 n);

extern "C" bool func_0043B638(BitSet *self, int a, u32 n) {
    func_0043B608(self, a, n);
    return (self->bits[n >> 5] & (1 << (n & 31))) != 0;
}
