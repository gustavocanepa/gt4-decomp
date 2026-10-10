typedef int s32;

struct Obj {
    char pad[0x12C8];
    s32 unk12C8;
};

extern "C" void ModelSet2__begin(s32 arg0, s32 arg1);

extern "C" void func_003D56A0(struct Obj *arg0) {
    ModelSet2__begin(arg0->unk12C8, 0);
}
