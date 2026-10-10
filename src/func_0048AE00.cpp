typedef float f32;

struct Quat { f32 x, y, z, w; };
extern "C" void func_0057D8A0(f32, f32 *, f32 *);

extern "C" void func_0048AE00(Quat *q, f32 angle) {
    f32 s, c;
    func_0057D8A0(angle * 0.5f, &s, &c);
    q->x = s;
    q->y = 0.0f;
    q->z = 0.0f;
    q->w = c;
}
