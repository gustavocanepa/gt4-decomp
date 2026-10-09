typedef int s32;

struct S { void *unk0; };

extern void func_005C1628(S *);
extern char D_00687E10;

void func_0043A408(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = &D_00687E10;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
