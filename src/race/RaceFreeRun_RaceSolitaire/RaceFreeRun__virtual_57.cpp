typedef int s32;

struct Obj {
    char pad[0x1AA0];
    s32 unk1AA0;
};

extern "C" void func_00346DA0(s32 arg0, struct Obj *arg1, s32 arg2);

extern "C" void RaceFreeRun__virtual_57(s32 arg0, struct Obj *arg1) {
    arg1->unk1AA0 = 1;
    func_00346DA0(arg0 + 0xE560, arg1, 1);
}
