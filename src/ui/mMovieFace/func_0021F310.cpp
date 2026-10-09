typedef int s32;

struct Obj {
    char pad0[0x118];
    char sub[0x158 - 0x118];
    s32 unk158;
};

extern "C" void func_005A609C(char *arg0, s32 arg1);

extern "C" void func_0021F310(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk158 = arg1;
    func_005A609C((char *)arg0 + 0x118, arg2);
}
