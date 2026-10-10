extern "C" void *func_005A48D8(void *p, int c, int n);
extern "C" void func_00371370(void *self);
extern "C" void func_00371530(void *self, void *a, void *b);

struct Vec3 {
    float x, y, z;
};

extern "C" void func_00371790(void *self) {
    Vec3 a;
    Vec3 b;
    Vec3 *pa = &a;
    Vec3 *pb = &b;
    func_005A48D8(pa, 0, sizeof(Vec3));
    func_005A48D8(pb, 0, sizeof(Vec3));
    func_00371370(self);
    func_00371530(self, pa, pb);
}
