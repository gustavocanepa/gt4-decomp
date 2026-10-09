typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_0055ACC8(s32 arg0, struct Obj *arg1);

extern "C" void func_0055C268(struct Obj *arg0) {
    func_0055ACC8(arg0->unk10, arg0);
}
