struct S { char pad[0x10]; int unk10; };
extern void func_00436CE8(int);

void func_005CC280(S *arg0)
{
    func_00436CE8(arg0->unk10);
}
