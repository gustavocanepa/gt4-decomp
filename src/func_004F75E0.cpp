typedef int s32;
typedef unsigned int u32;

extern "C" void func_005A6AB0(void *buf, s32 arg1, s32 arg2);
extern "C" u32 func_00509810(void *buf, s32 arg1);

extern "C" s32 func_004F75E0(void *unused, s32 arg1, s32 arg2)
{
    char buf[0x70];
    s32 s0 = arg1;

    func_005A6AB0(buf, arg2, 0x64);
    return func_00509810(buf, s0) < 1;
}
