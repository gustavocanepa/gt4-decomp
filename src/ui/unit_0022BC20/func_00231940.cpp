struct S { char pad[0x10]; int unk10; };
extern void func_00250B98(int);

void func_00231940(S *arg0)
{
    func_00250B98(arg0->unk10);
}
