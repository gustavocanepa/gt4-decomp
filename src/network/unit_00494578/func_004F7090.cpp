typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void func_004F6FB8(s32 arg0, struct Obj *arg1);

extern "C" void func_004F7090(struct Obj *arg0) {
    func_004F6FB8(arg0->unk18, arg0);
}
