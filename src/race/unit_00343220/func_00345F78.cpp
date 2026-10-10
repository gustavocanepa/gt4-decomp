extern "C" void func_00345BE0(void *self, int n);
extern "C" void AutomobileControlRecord__Recorder__read(void *self, void *out);

extern "C" void func_00345F78(void *self, int n, int keep)
{
    char buf[0x20];
    if (!keep)
        func_00345BE0(self, n);
    for (int i = 0; i < n; i++) AutomobileControlRecord__Recorder__read(self, buf);
}
