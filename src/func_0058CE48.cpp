/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern char D_00657AD0[];
extern "C" void func_0058CDD8(void);

extern "C" s32 func_0058CE48(void) {
    char *p = D_00657AD0;
    if (p[0] == 0) func_0058CDD8();
    return p[4] == 'T';
}
