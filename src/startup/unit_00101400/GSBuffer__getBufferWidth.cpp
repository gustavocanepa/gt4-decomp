typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
};

extern "C" s32 GSBuffer__getBufferWidth(Obj *arg0) {
    return (arg0->unk8 + 0x3F) & ~0x3F;
}
