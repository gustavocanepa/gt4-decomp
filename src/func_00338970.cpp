typedef long long s64;

struct S { char pad[0xAB0]; s64 unkAB0; };

extern "C" void func_00338970(S *arg0, s64 arg1) {
    arg0->unkAB0 = arg1;
}
