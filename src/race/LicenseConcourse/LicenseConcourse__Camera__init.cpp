/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 {
    float x, y, z;
    void set(float v) { x = v; y = v; z = v; }
};
extern "C" int func_00429870(void *, void *);
namespace LicenseConcourse {
struct Camera {
    int valid;
    int id;
    int m8;
    float mC;
    Vec3 a, b, c;
    float m34;
    void init(void *p, void *name);
};
}

void LicenseConcourse::Camera::init(void *p, void *name)
{
    if (name && (id = func_00429870(p, name)) >= 0) {
        valid = 1;
    } else {
        valid = 0;
        id = 0;
    }
    mC = 0.0f;
    m8 = 0;
    float f = mC;
    a.set(f);
    b.set(f);
    c.set(f);
    m34 = f;
}
