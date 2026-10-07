struct S { char pad[0x10]; int unk10; };
extern void func_004371C8(int);

void func_005CCCF0(S *arg0)
{
    func_004371C8(arg0->unk10);
}
