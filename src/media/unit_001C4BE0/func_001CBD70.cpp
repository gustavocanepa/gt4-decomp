extern "C" char *func_005A5EF4(const char *s, int c); /* strchr */
extern "C" const char *D_00618D10;

extern "C" int func_001CBD70(char c)
{
    if (c == 0)
        return -1;
    const char *p = func_005A5EF4(D_00618D10, c);
    if (p == 0)
        return -1;
    return p - D_00618D10;
}
