typedef int s32;

struct Obj {
    char pad[0x7C];
    s32 unk7C;
};

extern "C" void func_0056EFE8(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_004EF790(Obj *arg0, s32 arg1, s32 arg2) {
    func_0056EFE8((char *)arg0 + 4, arg0->unk7C, arg1, arg2);
}
