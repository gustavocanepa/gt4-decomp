extern int D_0064CCAC;
extern void *D_008A1AF0[7];
extern "C" void func_00565A70(void *p);
extern "C" void func_005538C0(int h);

extern "C" void func_00553758(void)
{
    if (D_0064CCAC) {
        for (int i = 0; i < 7; i++) {
            if (D_008A1AF0[i])
                func_00565A70(D_008A1AF0[i]);
        }
        func_005538C0(D_0064CCAC);
    }
}
