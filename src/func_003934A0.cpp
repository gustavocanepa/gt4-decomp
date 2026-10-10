extern int D_006213E8;
extern "C" float func_00391CD8(void);
extern "C" void func_00463458(void *a, void *b, void *c, int limit, float x, float y);

extern "C" void func_003934A0(void *a, void *b, void *c, float x, float y) {
    if (D_006213E8 == 0)
        func_00463458(a, b, c, 0x7FFFFFFF, x * func_00391CD8(), y);
}
