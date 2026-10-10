typedef float f32;

struct V4 { f32 x, y, z, w; };
struct M4 { f32 m[16]; };
extern "C" void func_0048A970(V4 *, M4 *, f32, f32, f32);
extern "C" void func_004A7698(M4 *);

extern "C" void func_0042C928(f32 x, f32 y, f32 z, f32 w) {
    M4 m;
    V4 v;
    V4 *p = &v;
    p->x = x;
    p->y = y;
    p->z = z;
    p->w = w;
    func_0048A970(&v, &m, 0.0f, 0.0f, 0.0f);
    func_004A7698(&m);
}
