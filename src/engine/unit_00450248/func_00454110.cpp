extern "C" void func_004A7844(float x, float y, float z);
extern "C" void func_004A79B0(float a);
extern "C" void func_004A79D8(float a);

extern "C" void func_00454110(float *v, int flip)
{
    func_004A7844(v[0], v[1], v[2]);
    func_004A79B0(v[4]);
    func_004A79D8(flip ? -v[5] : v[5]);
    func_004A7844(flip ? v[6] * 0.5f : v[6] * -0.5f, 0.0f, 0.0f);
}
