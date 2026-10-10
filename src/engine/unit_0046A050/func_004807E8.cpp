struct Vec2 {
    float x, y;
    Vec2 &operator+=(const Vec2 &o) { x += o.x; y += o.y; return *this; }
};
struct Rect { char pad[0xC]; Vec2 a; Vec2 b; };
struct Ev { char pad[0x40]; Rect r; };
struct Obj { char pad[0x18]; Vec2 pos; char pad2[0x3C - 0x20]; Vec2 base; char pad3[0x78 - 0x44]; int active; };
extern "C" void func_0047DC88(Obj *, Vec2 *, int);

extern "C" void func_004807E8(Obj *o, Ev *e)
{
    if (!o->active) return;
    Rect &r = e->r;
    Vec2 d;
    d.x = r.a.x - r.b.x;
    d.y = r.a.y - r.b.y;
    func_0047DC88(o, &d, 1);
    o->base += d;
    o->pos = o->base;
}
