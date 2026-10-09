struct S { char pad[0x10]; int unk10; };
extern void func_004372E8(int);

void func_005CC908(S *arg0)
{
    func_004372E8(arg0->unk10);
}
