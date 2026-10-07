struct S { char pad[0x14]; int unk14; };
extern void func_002C3BA0(int);

void func_0023FB48(S *arg0)
{
    func_002C3BA0(arg0->unk14);
}
