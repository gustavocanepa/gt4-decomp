extern "C" void func_00345BE0(void *self, int n);
extern "C" void func_00345D70(void *self, void *out);

extern "C" void func_00345F78(void *self, int n, int keep)
{
    char buf[0x20];
    if (!keep)
        func_00345BE0(self, n);
    for (int i = 0; i < n; i++) func_00345D70(self, buf);
}
