typedef long long s64;

struct S {
    s64 dummy[0x2F];
} __attribute__((aligned(8)));

extern "C" void func_004441B8(S *arg0, S *arg1) {
    *arg0 = *arg1;
}
