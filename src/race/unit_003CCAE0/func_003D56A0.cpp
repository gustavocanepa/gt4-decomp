typedef int s32;

struct Obj {
    char pad[0x12C8];
    s32 unk12C8;
};

extern "C" void func_00455370(s32 arg0, s32 arg1);

extern "C" void func_003D56A0(struct Obj *arg0) {
    func_00455370(arg0->unk12C8, 0);
}
