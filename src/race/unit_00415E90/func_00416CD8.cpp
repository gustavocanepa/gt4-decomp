typedef int s32;

extern "C" s32 func_00416D10(s32 arg0, s32 arg1);
extern "C" void func_00418EE0(s32 arg0, s32 arg1);

extern "C" s32 func_00416CD8(s32 arg0, s32 arg1) {
    func_00418EE0(arg0, arg1);
    return func_00416D10(arg0, arg1);
}
