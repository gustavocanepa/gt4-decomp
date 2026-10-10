/* compiler: ee-gcc2.9-991111 */
int func_005B0750(const char *fmt, ...);
void func_005AED18(int usec);
int func_005B1BB0(void *sema);
extern int D_00655ED0;
extern char D_006CE0E8[];
extern char D_00657A40[];

int func_00580A60(int nowait)
{
    if (nowait == 0) {
        if (D_00655ED0 > 0)
            func_005B0750(D_006CE0E8);
        while (func_005B1BB0(D_00657A40))
            func_005AED18(4000);
        return 0;
    }
    return func_005B1BB0(D_00657A40);
}
