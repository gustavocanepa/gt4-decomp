extern "C" void func_004AB040(int id);
extern "C" void func_004A29A8(int on);
extern "C" void func_004A2980(int v);
extern "C" int D_00623898;
extern "C" int D_006238B8;

extern "C" void func_004554D0(void)
{
    func_004AB040(4);
    func_004AB040(3);
    if (D_00623898)
        func_004A29A8(1);
    if (D_006238B8)
        func_004A2980(-1);
}
