struct Bits {
    char pad[0x40];
    unsigned int w[8];
    bool test(int i) const { return (w[i >> 5] & (1 << (i & 0x1F))) != 0; }
};
struct Obj {
    char pad[0x54];
    Bits bits;
};

extern "C" int func_00407C40(Obj *o, int n)
{
    Bits *b = &o->bits;
    if (!b->test(n))
        return -1;
    int c = 0;
    for (int i = 0; i < n; i++)
        if (b->test(i))
            c++;
    return c;
}
