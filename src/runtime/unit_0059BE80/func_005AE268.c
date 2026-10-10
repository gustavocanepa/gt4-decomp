/* compiler: ee-gcc2.9-991111 */
extern int D_006582A0;
extern int func_005AF408(void);
extern int func_005AF1C0(int a, int b);

int func_005AE268(int mode, int a, int b)
{
    if (mode == 1 || mode == 2) {
        if (D_006582A0 == 0) {
            if (func_005AF408() == 0)
                return -1;
            D_006582A0 = 1;
        }
        return func_005AF1C0(a, b);
    }
    return -1;
}
