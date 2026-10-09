struct S { char pad[0x10]; int unk10; };
extern void func_004363A0(int);

void func_005CD2B8(S *arg0)
{
    func_004363A0(arg0->unk10);
}
