typedef int s32;

extern "C" s32 func_004442B8(s32 arg0);
extern "C" void func_004442B0(s32 arg0);

extern "C" s32 func_00444190(s32 arg0)
{
    s32 s0 = arg0;
    func_004442B0(s0);
    return func_004442B8(s0);
}
