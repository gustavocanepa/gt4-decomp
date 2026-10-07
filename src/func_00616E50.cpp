struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int D_0068A3F8;

void func_00616E50(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_0068A3F8;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
