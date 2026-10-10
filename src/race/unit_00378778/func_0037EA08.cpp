static inline float sqrtf_(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    void set(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};

extern "C" int func_0034C518(void *obj, int kind, int index, Vec3 *pos);
extern "C" void func_005F5268(Vec3 *v, Vec3 *sub);
extern "C" float func_005F5010(Vec3 *v);

extern "C" float func_0037EA08(void *obj, Vec3 *target)
{
    Vec3 d;
    Vec3 pos;
    if (func_0034C518(obj, 6, 0, &pos) < 0)
        return 30.0f;
    d.set(pos.x, pos.y, pos.z);
    func_005F5268(&d, target);
    return sqrtf_(func_005F5010(&d));
}
