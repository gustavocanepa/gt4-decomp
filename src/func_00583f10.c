/* compiler: ee-gcc2.9-991111 */
struct G { int a; int b; int c; int d; };
extern struct G D_00875878;
int func_00583F10(void) {
    if (D_00875878.d == 0) return 0;
    return D_00875878.c;
}
