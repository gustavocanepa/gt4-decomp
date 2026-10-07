typedef int s32;

struct S { void *unk0; };

extern void func_005C1628(S *);
extern char D_006638D0;

void func_0020FCE0(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = &D_006638D0;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
