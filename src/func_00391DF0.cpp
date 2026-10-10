extern "C" int D_006213EC;
extern "C" int D_006213F0;
extern "C" void func_00391D58(float scale, float alpha);

extern "C" void func_00391DF0(void)
{
    float scale = 1.0f;
    if (D_006213EC)
        scale = 0.45f;
    if (D_006213F0)
        scale = 0.2f;
    func_00391D58(scale, 1.0f);
}
