struct S {
    int unk0;
};

extern void func_005C1628(S *);
extern int MEventFilter__vtable;

void MEventFilter__structor_6(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk0 = (int)&MEventFilter__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
