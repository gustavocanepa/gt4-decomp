struct S { char pad[0x10]; int unk10; };
extern void func_00437380(int);

void func_005CBDD0(S *arg0)
{
    func_00437380(arg0->unk10);
}
