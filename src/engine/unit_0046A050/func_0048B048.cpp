typedef float f32;

struct Quat {
    f32 x, y, z, w;
};

extern "C" void func_0057D8A0(f32 a, f32 *s, f32 *c);

extern "C" void func_0048B048(Quat *q, f32 angle) {
    f32 s, c;
    func_0057D8A0(angle * 0.5f, &s, &c);
    q->x = 0.0f;
    q->y = 0.0f;
    q->z = s;
    q->w = c;
}
