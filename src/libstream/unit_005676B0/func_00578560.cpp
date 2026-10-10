typedef long long s64;
extern "C" {
s64 func_005B8450(void);
void __udivdi3(s64 a, int b);
}
extern "C" void func_00578560(void) {
    __udivdi3(func_005B8450() * 0x7D, 0x4800);
}
