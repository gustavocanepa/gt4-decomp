typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_004F70F0(s32 arg0, struct Obj *arg1);

extern "C" void func_004F70F8(struct Obj *arg0) {
    func_004F70F0(arg0->unk10, arg0);
}
