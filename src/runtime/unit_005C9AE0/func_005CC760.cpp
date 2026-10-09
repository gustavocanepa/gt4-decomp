typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_00436FE0(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_005CC760(struct Obj *arg0, s32 arg1) {
    func_00436FE0(arg0->unk10, arg1, 0);
}
