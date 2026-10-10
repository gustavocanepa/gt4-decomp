/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern s32 D_00657A7C;
extern char D_00875858[];
extern "C" s32 func_005835B0(s32, s32, s32, s32, void *);

extern "C" long long func_00583540(void) {
    D_00657A7C = 1;
    return func_005835B0(0, 0, 0, 8, D_00875858);
}
