/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x, y; };
struct Tri { Vec2 a, b, c; };
struct TriBuf { int pad; int room; int pad2; Tri *cur; };

extern "C" void func_004854F8(TriBuf *buf, const Vec2 *a, const Vec2 *b, const Vec2 *c)
{
    if (buf->room > 0) {
        Tri *t = buf->cur;
        t->a.x = a->x;
        t->a.y = a->y;
        t->b.x = b->x;
        t->b.y = b->y;
        t->c.x = c->x;
        t->c.y = c->y;
        buf->cur++;
        buf->room--;
    }
}
