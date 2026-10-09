typedef int s32;

struct S { char pad[0x8]; void *unk8; };

extern void func_005C1628(S *);
extern char PauseBase__vtable;

void PauseBase__structor_1(S *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk8 = &PauseBase__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
