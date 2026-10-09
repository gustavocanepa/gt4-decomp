typedef int s32;

struct Obj {
    char pad[0x38];
    s32 unk38;
};

extern "C" void func_004AD368(s32 arg0, struct Obj *arg1);

extern "C" void func_0060AFD0(struct Obj *arg0) {
    func_004AD368(arg0->unk38, arg0);
}
