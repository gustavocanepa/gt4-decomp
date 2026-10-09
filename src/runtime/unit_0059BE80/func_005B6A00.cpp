typedef int s32;

extern "C" void func_005B6430(s32 a0, s32 a1, s32 a2, void *a3);

extern "C" void func_005B6A00(s32 a0, s32 a1, s32 a2)
{
    char buf[0x10];
    func_005B6430(a0, a1, a2, buf);
}
