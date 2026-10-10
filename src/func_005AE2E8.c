/* compiler: ee-gcc2.9-991111 */
extern int func_005AF408(void);
extern int func_005AF338(int a, int b);
extern int D_006582A0;

int func_005AE2E8(int mode, int a, int b)
{
    if (mode == 0) {
        if (D_006582A0 == 0) {
            if (func_005AF408() == 0)
                return -1;
            D_006582A0 = 1;
        }
        return func_005AF338(a, b);
    }
    return -1;
}
