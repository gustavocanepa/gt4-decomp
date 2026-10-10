/* compiler: ee-gcc2.9-991111 */
int func_005B72A8(void);
void func_005B72F8(void);
void func_005B05C0(void);
void func_005AF850(void (*fn)(void), int *result, unsigned int mask, void *a, void *b);

void func_005B06E0(void *a, void *b)
{
    int result = 0;
    int state = func_005B72A8();
    func_005AF850(func_005B05C0, &result, 0xFFFFFFFF, a, b);
    if (state)
        func_005B72F8();
}
