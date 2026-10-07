struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int D_0065B7E0;

void func_005FDE08(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_0065B7E0;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
