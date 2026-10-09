struct S { char pad[0x10]; int unk10; };
extern void func_00250CE0(int);

void func_002319A0(S *arg0)
{
    func_00250CE0(arg0->unk10);
}
