/* compiler: ee-gcc2.9-991111 */
typedef void (*Handler)(void);

extern Handler D_00874D80;
extern void *D_00874D84;

int func_005809C0(int);
int func_005B72A8(void);
void func_005B72F8(void);

Handler func_0057FEA8(Handler handler)
{
    Handler old;
    int state;

    if (func_005809C0(1) != 0)
        return 0;
    state = func_005B72A8();
    old = D_00874D80;
    D_00874D80 = handler;
    __asm__ volatile("sw $gp, %0" : "=m"(D_00874D84));
    if (state)
        func_005B72F8();
    return old;
}
