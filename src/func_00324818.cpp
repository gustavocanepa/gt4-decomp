struct S { char pad[0x10]; int unk10; };
extern void func_003166D8(int);

void func_00324818(S *arg0)
{
    func_003166D8(arg0->unk10);
}
