struct S { char pad[0x10]; int unk10; };
extern void func_00437078(int);

void func_005CC7D8(S *arg0)
{
    func_00437078(arg0->unk10);
}
