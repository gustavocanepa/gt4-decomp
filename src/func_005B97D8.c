/* compiler: ee-gcc2.9-991111 */
typedef void (*Handler)(void);
extern Handler D_00659648;
void func_005B9D00(void);
int func_005AD950(int code, void (*handler)(void));

Handler func_005B97D8(Handler h)
{
    D_00659648 = h;
    func_005AD950(1, func_005B9D00);
    func_005AD950(2, func_005B9D00);
    func_005AD950(3, func_005B9D00);
    return h;
}
