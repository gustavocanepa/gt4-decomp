struct S { char pad[0x10]; int unk10; };
extern void func_00436C18(int);

void func_005CCDA0(S *arg0)
{
    func_00436C18(arg0->unk10);
}
