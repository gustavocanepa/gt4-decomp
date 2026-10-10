/* compiler: ee-gcc2.9-991111 */
extern int func_005B72A8(void);
extern void func_005B72F8(void);
extern void func_005B7B98(unsigned int mode);

int func_005B7E88(void) {
    int intr = func_005B72A8();
    unsigned int mode = *(volatile unsigned int *)0x10001010;
    if ((mode & 0x80) == 0) {
        if (intr)
            func_005B72F8();
        return 0;
    }
    func_005B7B98(mode & ~0xC80);
    if (intr)
        func_005B72F8();
    return 1;
}
