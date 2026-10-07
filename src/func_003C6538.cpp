typedef int s32;

struct S { char pad[0x8]; void *unk8; };

extern void func_005C1628(S *);
extern char D_00681BD0;

void func_003C6538(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk8 = &D_00681BD0;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
