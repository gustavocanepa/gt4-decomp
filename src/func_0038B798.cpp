typedef int s32;

struct Obj {
    char pad[0xE418];
    s32 unkE418;
};

extern "C" void func_00389D30(Obj *arg0, s32 arg1);

extern "C" void func_0038B798(Obj *arg0, s32 arg1) {
    func_00389D30(arg0, (arg0->unkE418 == 0) ? 0 : arg1);
}
