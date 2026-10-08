typedef int s32;

struct S {
    char pad0[0xFB4];
    s32 unkFB4;
};

extern "C" void func_005C1628(s32 arg0);
extern char D_00680790;

extern "C" void func_003BB9F8(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unkFB4 = (s32)&D_00680790;
    if (arg1)
    {
        func_005C1628((s32)arg0);
        return;
    }
}
