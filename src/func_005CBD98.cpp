struct S { char pad[0x10]; int unk10; };
extern void func_00436D60(int);

void func_005CBD98(S *arg0)
{
    func_00436D60(arg0->unk10);
}
