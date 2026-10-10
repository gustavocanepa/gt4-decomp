extern signed char D_006CC620[13];

int func_005B72A8(void);
int func_005AE780(int id);

void func_00577F10(void)
{
    int i;
    int state = func_005B72A8();

    for (i = 0; i < 13; i++)
        func_005AE780(D_006CC620[i]);
    if (state)
        __asm__ volatile("ei");
}
