typedef int s32;

struct Obj {
    char pad[0x9C];
    s32 unk9C;
};

extern "C" void func_00266438(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x80;
    v = v | (temp << 7);
    arg0->unk9C = v;
}
