typedef int s32;

extern char D_0083F600[];

extern "C" void func_0030ADA0(s32 arg0, void *arg1, void *arg2);

extern "C" void func_0030AF08(void *arg0, void *arg1, s32 *arg2) {
    func_0030ADA0(*arg2, arg1, D_0083F600);
}
