extern float D_008465E8;
extern "C" void func_004A7B40(float);

extern "C" void func_00456850(float t) {
    if (t < 0.0f)
        t = 0.0f;
    if (t > 1.0f)
        t = 1.0f;
    D_008465E8 = t;
    func_004A7B40(t);
}
