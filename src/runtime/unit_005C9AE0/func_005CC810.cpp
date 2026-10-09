struct S { char pad[0x10]; int unk10; };
extern void func_004370D8(int);

void func_005CC810(S *arg0)
{
    func_004370D8(arg0->unk10);
}
