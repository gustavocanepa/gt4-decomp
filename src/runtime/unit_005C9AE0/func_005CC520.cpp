struct S { char pad[0x10]; int unk10; };
extern void func_00436AB8(int);

void func_005CC520(S *arg0)
{
    func_00436AB8(arg0->unk10);
}
