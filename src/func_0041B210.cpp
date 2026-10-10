extern "C" void *func_0041A988(void *self, int i);
extern "C" void func_00418DE8(void *item);

extern "C" void func_0041B210(void *self)
{
    for (int i = 0; i < 20; i++)
        func_00418DE8(func_0041A988(self, i));
}
