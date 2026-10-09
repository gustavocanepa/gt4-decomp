struct S { char pad[0x10]; int unk10; };
extern void func_00436A00(int);

void func_005CC410(S *arg0)
{
    func_00436A00(arg0->unk10);
}
