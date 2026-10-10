extern "C" void func_0057C808(void *, void *);
extern "C" void func_0057C8B0(void *, void *);

extern "C" void func_0057C9D0(char *self) {
    char *a = self + 0x58;
    func_0057C808(self, a);
    func_0057C8B0(a, self + 0x68);
}
