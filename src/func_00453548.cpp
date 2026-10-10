typedef float f32;

struct Vec {
    f32 x, y, z, w;
};

extern Vec D_006AA8C0;
extern "C" void func_004A53F8(void);
extern "C" void func_004A7A54(void);
extern "C" void func_004A7AA8(Vec *out, const Vec *in);
extern "C" void func_004A5400(void);

extern "C" bool func_00453548(void) {
    Vec v;
    func_004A53F8();
    func_004A7A54();
    func_004A7AA8(&v, &D_006AA8C0);
    func_004A5400();
    return v.x <= 0.0f;
}
