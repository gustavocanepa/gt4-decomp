typedef int s32;

struct Obj {
    char pad[0x38];
    s32 unk38;
};

extern "C" void func_005F7830(Obj *arg0, s32 arg1) {
    s32 v = arg0->unk38;
    v = v & 0xFFFFFF;
    v = v | (arg1 << 24);
    arg0->unk38 = v;
}
