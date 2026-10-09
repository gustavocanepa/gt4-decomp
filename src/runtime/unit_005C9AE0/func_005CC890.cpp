typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_00437028(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_005CC890(struct Obj *arg0, s32 arg1) {
    func_00437028(arg0->unk10, arg1, 0);
}
