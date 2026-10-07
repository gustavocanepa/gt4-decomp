typedef int s32;

struct Obj {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_002661A0(Obj *arg0, s32 arg1) {
    s32 flags = arg0->unk98;
    s32 bits = flags & 0xB;
    if (arg1 != 0) {
        bits = bits | 4;
    }
    arg0->unk98 = (flags & ~0xF) | bits;
}
