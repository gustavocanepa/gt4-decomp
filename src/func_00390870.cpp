typedef int s32;

struct Obj {
    s32 unk0;
};

extern "C" void func_00452AC8(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_00390870(Obj *arg0, s32 arg1, s32 arg2) {
    func_00452AC8((char *)arg0 + 0x18, arg0->unk0, arg1, arg2);
}
