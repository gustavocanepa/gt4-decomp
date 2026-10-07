struct S { char pad[0x10]; int unk10; };
extern void func_00436A58(int);

void func_005CC488(S *arg0)
{
    func_00436A58(arg0->unk10);
}
