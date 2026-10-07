typedef short s16;
typedef int s32;

extern "C" void func_0045B0A0(void *arg0, s16 *arg1, s32 arg2);

extern "C" void func_0045AFA0(void *arg0, s16 arg1) {
    s16 local = arg1;
    func_0045B0A0(arg0, &local, 2);
}
