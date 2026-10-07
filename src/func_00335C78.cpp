typedef long long s64;

struct __attribute__((aligned(8))) S { char pad[0xAB0]; s64 unkAB0; };

extern "C" void func_00335C78(S *arg0, s64 arg1) {
    arg0->unkAB0 = arg1;
}
