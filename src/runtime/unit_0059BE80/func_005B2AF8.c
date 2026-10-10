/* compiler: ee-gcc2.9-991111 */
extern char D_008899E8[];
extern char D_0065829C[];
extern char *D_00658350;
int func_0057F188(const char *, const char *, int);

int func_005B2AF8(void)
{
    char *b = D_0065829C;
    char *a = D_008899E8;
    return func_0057F188(a, b, 4) && func_0057F188(a, D_00658350, 4) && func_0057F188(b, D_00658350, 4);
}
