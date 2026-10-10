/* compiler: ee-gcc2.9-991111 */
int func_005B72A8(void);
void func_005B72F8(void);
void func_005B7B98(unsigned int);
int func_005B8400(void);
void func_005B7F08(int);

int func_005B7DF8(void)
{
    int s = func_005B72A8();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (v & 0x80) {
        if (s) func_005B72F8();
        return 1;
    }
    func_005B7B98((v & ~0xC00) | 0x80);
    func_005B7F08(func_005B8400());
    if (s) func_005B72F8();
    return 0;
}
