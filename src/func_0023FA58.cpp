struct S { char pad[0x10]; int unk10; };
extern void func_002C3DB8(int);

void func_0023FA58(S *arg0)
{
    func_002C3DB8(arg0->unk10);
}
