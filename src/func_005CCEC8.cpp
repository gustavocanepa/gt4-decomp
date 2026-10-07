struct S { char pad[0x10]; int unk10; };
extern void func_004368F8(int);

void func_005CCEC8(S *arg0)
{
    func_004368F8(arg0->unk10);
}
