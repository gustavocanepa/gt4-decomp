typedef int s32;
typedef float f32;
char *func_0025BF60(void);
void func_002E9730(char *arg0, f32 fparg0, f32 fparg1) {
    char *t = func_0025BF60();
    if (*(s32 *)(arg0 + 0xC4) != 0) {
        *(f32 *)(t + 8) = fparg0;
        *(f32 *)(t + 0xC) = fparg1;
    } else {
        *(f32 *)(t + 8) = fparg1;
        *(f32 *)(t + 0xC) = fparg0;
    }
}
