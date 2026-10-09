typedef signed char s8;
typedef int s32;

extern "C" void func_002FFAC0(void *arg0, s8 *arg1, s32 arg2);

extern "C" void func_002FFAF0(void *arg0, s8 arg1) {
    s8 local = arg1;
    func_002FFAC0(arg0, &local, 1);
}
