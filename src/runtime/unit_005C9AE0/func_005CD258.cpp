struct S { char pad[0x10]; int unk10; };
extern void func_004365B8(int);

void func_005CD258(S *arg0)
{
    func_004365B8(arg0->unk10);
}
