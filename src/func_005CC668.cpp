struct S { char pad[0x10]; int unk10; };
extern void func_00437228(int);

void func_005CC668(S *arg0)
{
    func_00437228(arg0->unk10);
}
