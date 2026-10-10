struct Vec2 { float x, y; };
struct Poly { int n; Vec2 pts[1]; };

extern "C" void func_003C6B90(Poly *p, Vec2 *out)
{
    float x = 0.0f, y = 0.0f;
    if (p->n <= 0) { out->y = y; out->x = y; return; }
    for (int i = 0; i < p->n; i++) {
        x += p->pts[i].x;
        y += p->pts[i].y;
    }
    float n = p->n;
    x /= n;
    y /= n;
    out->x = x;
    out->y = y;
}
