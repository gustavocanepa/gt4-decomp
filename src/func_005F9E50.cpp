typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void func_005F9E50(Obj *arg0, s32 arg1) {
    s32 v = arg0->unk18;
    v = v & 0xFFFFFF;
    v = v | (arg1 << 24);
    arg0->unk18 = v;
}
