struct Vec3 {
    float x, y, z;
};

extern "C" void func_004A1638(int mode);
extern "C" void func_004A2808(int a, float b);
extern "C" void func_004AA1D8(float r, float g, float b, float a);
extern "C" void func_004A7288(float x0, float y0, float z0, float x1, float y1, float z1);

extern "C" void func_003D1A28(Vec3 *a, Vec3 *b) {
    func_004A1638(6);
    func_004A2808(0x44, 1.0f);
    func_004AA1D8(0.0f, 0.0f, 0.0f, 0x1.999998p-1f);
    func_004A7288(a->x, a->y, a->z, b->x, b->y, b->z);
}
