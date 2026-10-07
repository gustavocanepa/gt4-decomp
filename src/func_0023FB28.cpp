struct S { char pad[0x14]; int unk14; };
extern void func_002C3D90(int);

void func_0023FB28(S *arg0)
{
    func_002C3D90(arg0->unk14);
}
