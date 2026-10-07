struct S { char pad[0x10]; int unk10; };
extern void func_00436640(int);

void func_005CD278(S *arg0)
{
    func_00436640(arg0->unk10);
}
