/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x, y; };
extern "C" void func_0047DE58(float *out, const float *a, const float *b, float t);

extern "C" void func_0047E5F8(Vec2 *out, const Vec2 *a, const Vec2 *b, float t)
{
    func_0047DE58(&out->x, &a->x, &b->x, t);
    func_0047DE58(&out->y, &a->y, &b->y, t);
}
