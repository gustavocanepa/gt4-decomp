typedef long long s64;
extern "C" {
void func_004359B0(char *a, s64 b);
s64 func_0043AF68(void);
}
extern "C" void func_0043AFB0(char *arg0, s64 arg1) {
    char *p = arg0 + 0xB8E8;
    func_004359B0(p, arg1 + func_0043AF68());
}
