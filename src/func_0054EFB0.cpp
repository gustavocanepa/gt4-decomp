struct S { char pad[0x3E8]; int unkC; };
extern int D_0064C4B0;
extern void func_0054FD80(int);

void func_0054EFB0(S *arg0)
{
    if (D_0064C4B0 != 0) {
        func_0054FD80(arg0->unkC);
    }
}
