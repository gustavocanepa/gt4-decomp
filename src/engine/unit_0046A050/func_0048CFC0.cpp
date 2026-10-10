typedef int s32;
typedef float f32;

struct Vec2 {
    f32 x, y;
    Vec2() {}
    Vec2(const Vec2 &o) : x(o.x), y(o.y) {}
    Vec2 &operator=(const Vec2 &o) { x = o.x; y = o.y; return *this; }
};

extern "C" Vec2 func_0048CF78(s32, const Vec2 &);

extern "C" void func_0048CFC0(Vec2 *self, s32 arg1) {
    *self = func_0048CF78(arg1, *self);
}
