struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int D_0067E598;

void func_003A27C8(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&D_0067E598;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
