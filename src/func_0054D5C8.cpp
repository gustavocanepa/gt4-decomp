#define IPU_CTRL (*(volatile int *)0x10002010)
#define IPU_BP (*(volatile unsigned int *)0x10002020)

extern "C" void func_0054D888(void);

extern "C" void func_0054D5C8(void)
{
    while (IPU_CTRL < 0) {
        if (((IPU_BP >> 8) & 0xF) == 0)
            func_0054D888();
    }
}
