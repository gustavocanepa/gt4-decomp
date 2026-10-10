/* Function-local static object, written out: guard, constructor, atexit destructor. */
extern int D_00620184;
extern char D_008424C0[];

extern "C" void *func_00328800(void *obj, int a, int b);
extern "C" int func_005A2ED0(void (*fn)(void));
extern "C" void func_003295B8(void);

extern "C" void *func_003294C0(void)
{
    int *guard = &D_00620184;
    if (*guard == 0) {
        func_00328800(D_008424C0, 0, 0);
        *guard = 1;
        func_005A2ED0(func_003295B8);
    }
    return D_008424C0;
}
