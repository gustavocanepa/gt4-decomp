struct S { char pad[0x10]; int unk10; };
extern void func_004367E0(int);

void func_005CBCF0(S *arg0)
{
    func_004367E0(arg0->unk10);
}
