struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int MAction__vtable;

void MAction__structor_0(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&MAction__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
