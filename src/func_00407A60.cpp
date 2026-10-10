struct Flags {
    char pad[0x40];
    unsigned int words[1];
    int test(int i) const { return words[i >> 5] & (1 << (i & 31)); }
};
struct Obj { int pad[2]; Flags flags; };

extern "C" int func_00407A60(Obj *o, int n)
{
    int count = 0;
    for (int i = 0; i < 13; i++) {
        if (o->flags.test(i))
            count++;
        if (count > n)
            return i;
    }
    return -1;
}
