/* compiler: ee-gcc2.9-991111 */
extern char *func_0058B3C8(void);
extern int func_005864E0(char *p, int size, int flag);

int func_00583D40(void) {
    char *p = func_0058B3C8();
    if ((int)p & 3)
        return -1;
    while (func_005864E0(p, 0x10, 1) >= 0)
        p += 0x20;
    return 0;
}
