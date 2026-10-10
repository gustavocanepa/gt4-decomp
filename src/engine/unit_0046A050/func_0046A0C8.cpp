/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Probe {
    float x;
    float z;
    float y;
    int id;
    float height;
    char pad14[0x1C];
    unsigned char miss;
    char pad31[0xF];
    Probe(Vec3 v, int i) : x(v.x), z(v.z), y(-v.y), id(i) {}
};

struct Ctx;
extern "C" void func_00395760(Ctx *c, Probe *p);

extern "C" float func_0046A0C8(Ctx *c, int *id, int *miss, float x, float y, float z) {
    Probe p(Vec3(x, y, z), *id);
    func_00395760(c, &p);
    *miss = p.miss;
    if (p.miss)
        return 0.0f;
    *id = p.id;
    return p.height;
}
