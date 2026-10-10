extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_004611F8(int v);
extern "C" char D_008468E8[];
extern "C" int D_008468D0;

extern "C" void func_004613F0(int v)
{
    func_00576788(D_008468E8);
    if (v != D_008468D0)
        func_004611F8(v);
    func_005767C0(D_008468E8);
}
