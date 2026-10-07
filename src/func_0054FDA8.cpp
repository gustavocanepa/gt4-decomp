struct S { char pad[0xC]; int unkC; };
extern int D_0064C4C4;
extern void func_00564770(int);

void func_0054FDA8(S *arg0)
{
    if (D_0064C4C4 != 0) {
        func_00564770(arg0->unkC);
    }
}
