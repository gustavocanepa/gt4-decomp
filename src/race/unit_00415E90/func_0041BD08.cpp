struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj;

extern "C" unsigned char *func_0041B578(unsigned char *p, void *out);
extern "C" unsigned char *func_0041B6E8(Obj *self, unsigned char *p);
extern "C" void func_0041BC38(Obj *self, Vec4 *v);

extern "C" unsigned char *func_0041BD08(Obj *self, unsigned char *p)
{
    Vec4 v;
    p = func_0041B6E8(self, p);
    p = func_0041B578(p, &v.x);
    p = func_0041B578(p, &v.y);
    p = func_0041B578(p, &v.z);
    func_0041BC38(self, &v);
    return p;
}
