struct BitSet {
    char pad0[0x40];
    unsigned int words[1];
    int test(int i) const { return words[i >> 5] & (1 << (i & 31)); }
};

struct Obj {
    int pad0[2];
    BitSet set;
};

extern "C" int func_00407BC0(Obj *o, int idx) {
    BitSet *b = &o->set;
    if (!b->test(idx))
        return -1;
    int n = 0;
    for (int i = 0; i < idx; i++) {
        if (b->test(i))
            n++;
    }
    return n;
}
