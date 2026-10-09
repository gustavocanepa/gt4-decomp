typedef int s32;
typedef float f32;

extern "C" void func_00395930(s32 arg0, f32 *vec, s32 *parg1, void *buf, s32 arg2);

extern "C" void func_003958D8(s32 arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 savedArg1 = arg1;
    f32 vec[3];
    char buf[0x10];

    vec[0] = fparg0;
    vec[1] = fparg1;
    vec[2] = fparg2;

    func_00395930(arg0, vec, &savedArg1, buf, arg2);
}
