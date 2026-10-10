/* compiler: ee-gcc2.9-991111 */
typedef void (*Handler)(int);

extern Handler D_00659650[];
extern void func_005B9F40(int sig);
extern void func_005AD950(int sig, void (*f)(int));
extern void func_005AD960(int sig, void (*f)(int));

Handler func_005B9838(int sig, Handler h)
{
    Handler old;

    if ((unsigned int)(sig - 1) >= 13)
        return (Handler)0xFFFFFFFF;
    old = D_00659650[sig];
    D_00659650[sig] = h;
    if ((unsigned int)(sig - 1) < 3)
        func_005AD950(sig, func_005B9F40);
    else
        func_005AD960(sig, func_005B9F40);
    return old;
}
