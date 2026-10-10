typedef int s32;
typedef float f32;
void func_003B0820(char *a);
s32 func_003B4040(void *, s32, f32, f32, f32, f32, f32, f32, f32);
s32 func_003B1AA0(char *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6) {
    s32 r;
    func_003B0820(arg0 + 0x7E0);
    r = func_003B4040(arg0, arg1, fparg0, fparg1, fparg2, fparg3, fparg4, fparg5, fparg6);
    if (r != 0) {
        *(s32 *)(arg0 + 0x7C0) += 1;
    }
    return r;
}
