struct S { char pad[0x10]; int unk10; };
extern void func_00437348(int);

void func_005CC940(S *arg0)
{
    func_00437348(arg0->unk10);
}
