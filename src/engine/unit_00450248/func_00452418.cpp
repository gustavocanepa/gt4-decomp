extern "C" void RaceEntryCar__update(int mode);
extern "C" void func_004A53F8(void);
extern "C" void func_0049AB58(float a);
extern "C" void func_004A7844(float x, float y, float z);

extern "C" void func_00452418(float a, float b)
{
    RaceEntryCar__update(1);
    func_004A53F8();
    func_0049AB58(a);
    RaceEntryCar__update(0);
    func_004A53F8();
    func_004A7844(0.0f, b, 0.0f);
}
