/* compiler: ee-gcc2.9-991111 */
int func_005B72A8(void);
void func_005B72F8(void);
int func_005AD9F0(void *arg);

int func_005AE780(void *arg)
{
    int status;
    int ret;

    __asm__ volatile("mfc0 %0, $12" : "=r"(status));
    status &= 0x10000;
    if (status)
        func_005B72A8();
    ret = func_005AD9F0(arg);
    __asm__ volatile("sync.l");
    if (status)
        func_005B72F8();
    return ret;
}
