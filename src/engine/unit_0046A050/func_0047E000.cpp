struct Rect { float x0, y0, x1, y1; };
struct Vec2 { float x, y; };
extern "C" int func_0047E000(const Rect *r, const Vec2 *p)
{
    if (p->x < r->x0 || p->y < r->y0 || r->x1 < p->x || r->y1 < p->y) return 0; return 1;
}
