typedef int s32;

struct S {
    char pad0[0xC];
    s32 unkC;
};

extern "C" void func_005C1628(S *arg0);
extern char RaceResultBase__vtable;

extern "C" void RaceResultBase__structor_2(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unkC = (s32)&RaceResultBase__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
