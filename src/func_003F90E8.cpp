extern "C" float func_003F90C8(int a, int b);
extern "C" void func_003677F8(int level, int a, int b, int c);

extern "C" float func_003F90E8(int a, int b, int c, int d, int e)
{
    float v = func_003F90C8(a, b);
    func_003677F8((int)(v * 127.0f), c, d, e);
    return v;
}
