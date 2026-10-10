struct Block {
    long w[0x102];
};

struct Obj {
    char pad[0x1C8];
    Block block;
};

extern "C" void func_005F3A48(Obj *o, const Block *b) {
    o->block = *b;
}
