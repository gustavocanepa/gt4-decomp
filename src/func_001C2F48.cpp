typedef int s32;

struct Obj {
    char pad[0x23C];
    s32 unk23C;
};

extern "C" void func_001C3958(struct Obj *arg0);

extern "C" void func_001C2F48(struct Obj *arg0, s32 arg1) {
    arg0->unk23C = arg1;
    func_001C3958(arg0);
}
