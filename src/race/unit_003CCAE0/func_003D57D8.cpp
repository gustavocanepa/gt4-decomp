typedef int s32;

struct Obj003D57D8 {
    char pad0[0x12C8];
    s32 unk12C8;
};

extern "C" void ModelSet2__end(s32 arg0);

extern "C" void func_003D57D8(struct Obj003D57D8 *arg0) {
    ModelSet2__end(arg0->unk12C8);
}
