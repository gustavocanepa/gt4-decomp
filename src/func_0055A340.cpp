extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" void func_0055A1A8(int *obj, int arg);
extern "C" char D_00655340[];

extern "C" void func_0055A340(int *obj, int arg)
{
    func_00576100(D_00655340);
    func_0055A1A8(obj, arg);
    *obj = 0;
    func_00576140(D_00655340);
}
