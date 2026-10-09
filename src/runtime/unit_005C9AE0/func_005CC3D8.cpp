struct S { char pad[0x10]; int unk10; };
extern void func_004369C0(int);

void func_005CC3D8(S *arg0)
{
    func_004369C0(arg0->unk10);
}
