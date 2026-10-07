typedef int s32;

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_00266060(Obj *arg0, s32 arg1) {
    s32 flags = arg0->unk98;
    s32 bits = flags & 0xE;
    if (arg1 != 0) {
        bits = bits | 1;
    }
    arg0->unk98 = (flags & ~0xF) | bits;
}
