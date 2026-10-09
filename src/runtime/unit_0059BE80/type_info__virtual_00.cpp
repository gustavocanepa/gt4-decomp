struct S {
    char pad[0x4];
    int unk4;
};

extern void func_005C1628(S *);
extern int type_info__vtable;

void type_info__virtual_00(S *arg0, int arg1)
{
    arg1 = arg1 & 1;
    arg0->unk4 = (int)&type_info__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
