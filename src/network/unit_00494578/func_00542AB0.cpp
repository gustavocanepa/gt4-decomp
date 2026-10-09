typedef int s32;

extern "C" s32 func_00542AE8(s32 arg0, s32 arg1);
extern "C" void func_00543BE0(s32 arg0, s32 arg1);

extern "C" s32 func_00542AB0(s32 arg0, s32 arg1) {
    func_00543BE0(arg0, arg1);
    return func_00542AE8(arg0, arg1);
}
