struct S { char pad[0x10]; int unk10; };
extern void func_00250BF8(int);

void func_00231960(S *arg0)
{
    func_00250BF8(arg0->unk10);
}
