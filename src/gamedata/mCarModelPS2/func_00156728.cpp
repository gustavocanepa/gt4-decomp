typedef int s32;

struct Obj {
    char pad[0x89C];
    s32 unk89C;
};

struct Target;

extern "C" void func_00452FA0(Target *arg0, s32 arg1, s32 arg2);

extern "C" void func_00156728(Obj *arg0, s32 arg1) {
    s32 t = arg0->unk89C;
    func_00452FA0((Target *)((char *)arg0 + 0x2A4), arg1, t);
}
