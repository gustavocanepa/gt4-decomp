struct S { char pad[0x10]; int unk10; };
extern void func_00250C58(int);

void func_00231980(S *arg0)
{
    func_00250C58(arg0->unk10);
}
