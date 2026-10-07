struct S { char pad[0x10]; int unk10; };
extern void func_00436C88(int);

void func_005CBEE8(S *arg0)
{
    func_00436C88(arg0->unk10);
}
