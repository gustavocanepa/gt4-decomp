/* compiler: ee-gcc2.9-991111 */
struct Chan { int m0; int state; int m8; int result; char pad[0x324]; };
extern struct Chan D_0087FA80[];
int func_0058FD28(int port);

int func_0058F348(int port)
{
    int r; if ((r = func_0058FD28(port)) < 0) return r; D_0087FA80[port].result = r; D_0087FA80[port].state = 1; return r;
}
