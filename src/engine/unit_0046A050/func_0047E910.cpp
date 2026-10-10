struct Vec3 {
    float x, y, z;
    float pad;
};

struct Obj {
    char pad0[0x6E28];
    float angle;
    float dist;
};

static inline float sqrtf_(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" Vec3 func_004A7AA8(const void *src);
extern "C" float func_0057D6C0(float a, float b);
extern const char D_006ADDC8[];

extern "C" void func_0047E910(Obj *o) {
    Vec3 v = func_004A7AA8(D_006ADDC8);
    float d = sqrtf_(v.x * v.x + v.y * v.y + v.z * v.z);
    o->angle = func_0057D6C0(d, 0x1.999998p-2f);
    o->dist = d;
}
