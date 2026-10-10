/* compiler: ee-gcc2.9-991111 */
extern char D_00889EA8[];
extern char D_0065829C[];
extern char *D_0065835C;
int func_0057F188(const char *, const char *, int);

int func_005B6368(void)
{
    char *b = D_0065829C;
    char *a = D_00889EA8;
    return func_0057F188(a, b, 4) && func_0057F188(a, D_0065835C, 4) && func_0057F188(b, D_0065835C, 4);
}
