typedef int s32;

struct S { char pad[0x8]; void *unk8; };

extern void func_005C1628(S *);
extern char D_0067DFA0;

void func_005F6E90(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk8 = &D_0067DFA0;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
