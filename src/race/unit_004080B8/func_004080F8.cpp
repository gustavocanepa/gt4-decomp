typedef int s32;

extern "C" s32 func_003E7488(s32 arg0);
extern "C" void func_00408078(s32 arg0);

extern "C" s32 func_004080F8(s32 arg0)
{
    s32 s0 = arg0;
    func_00408078(s0);
    return func_003E7488(s0);
}
