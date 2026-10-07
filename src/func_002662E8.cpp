typedef int s32;

struct Obj {
    char pad[0x9C];
    s32 unk9C;
};

extern "C" void func_002662E8(struct Obj *arg0, s32 arg1) {
    arg0->unk9C = (arg0->unk9C & ~1) | (arg1 != 0);
}
