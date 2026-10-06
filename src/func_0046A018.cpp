struct S { char pad[0x18]; int unk18; };
extern void func_005C1628(S *);
extern int D_00668508;

void func_0046A018(S *arg0, int arg1)
{
  arg1 = arg1 & 1;
  arg0->unk18 = (int)&D_00668508;
  if (arg1)
  {
    func_005C1628(arg0);
    return;
  }
}
