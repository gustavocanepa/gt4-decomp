extern "C" void func_00455528(void *a, int c);
extern "C" void func_00455370(void *a, int c);
extern "C" void func_00455708(void *a, int b, int c);
extern "C" void func_004554D0(void *a);

extern "C" void func_00455598(void *a, int b, int c) {
    if (b < 0)
        return func_00455528(a, c);
    func_00455370(a, c);
    func_00455708(a, b, c);
    func_004554D0(a);
}
