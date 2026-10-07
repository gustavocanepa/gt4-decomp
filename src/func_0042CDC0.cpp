struct S {
    char pad[0x4];
    int unk4;
};

extern void func_005C1628(S *);
extern int D_00687550;

void func_0042CDC0(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk4 = (int)&D_00687550;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
