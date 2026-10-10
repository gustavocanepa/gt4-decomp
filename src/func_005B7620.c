/* compiler: ee-gcc2.9-991111 */
extern void func_005ADD50(unsigned int *status);
extern void func_005ADD40(unsigned int *status);

int func_005B7620(void)
{
    unsigned int st[2];

    func_005ADD50(&st[0]);
    st[1] = (st[0] & ~0xE000) | 0x2000;
    func_005ADD40(&st[1]);
    func_005ADD50(&st[1]);
    func_005ADD40(&st[0]);
    return ((st[1] >> 13) & 7) == 0;
}
