extern "C" void func_003974D8(void *self, int n, float x);
extern "C" void func_00397768(void *self, int n);

extern "C" void func_003973D0(void *self, float x)
{
    func_003974D8(self, 1, 100.0f);
    func_00397768(self, 1);
    func_003974D8(self, 1, -x);
    func_00397768(self, 1);
}
