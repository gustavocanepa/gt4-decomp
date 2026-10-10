/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tint {
    float r, g, b, a, sx, sy;
    void reset()
    {
        sy = 1.0f;
        b = 1.0f;
        g = 1.0f;
        r = 1.0f;
        a = 0.0f;
        sx = 1.0f;
    }
};

struct Obj {
    int id;
    Tint t0;
    Tint t1;
    float m34;
    int m38;
    unsigned int flags;
};

extern "C" void func_00400758(Obj *o, int id)
{
    o->id = id;
    o->flags &= ~0xFF;
    o->flags &= ~0xFF00;
    o->m38 = 0;
    o->m34 = 0.0f;
    o->t0.reset();
    o->t1.reset();
}
