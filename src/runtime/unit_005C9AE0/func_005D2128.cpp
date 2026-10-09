struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int D_00660CD8;

void func_005D2128(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_00660CD8;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
