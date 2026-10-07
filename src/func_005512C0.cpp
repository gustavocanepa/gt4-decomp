typedef int s32;

struct Struct0086F800 {
    s32 unk0;
    char pad[0x3C];
    s32 unk40;
};

extern Struct0086F800 D_0086F8C0;

extern "C" void func_00578500(s32 arg0);
extern "C" void func_00578168(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_005512C0(s32 arg0) {
    func_00578500(D_0086F8C0.unk0);
    D_0086F8C0.unk40 = arg0;
    func_00578168(&D_0086F8C0, 2, 0, 0, 0);
}
