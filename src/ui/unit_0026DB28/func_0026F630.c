typedef int s32;
typedef float f32;

struct Rot { s32 identity; f32 c; f32 s; };
struct Pt { f32 x; f32 y; };
struct Quad { struct Pt p[4]; };

void func_0026F630(struct Rot *self, f32 *minx, f32 *miny, f32 *maxx, f32 *maxy) {
    f32 c, s;
    f32 y0, x0, x1, y1, cx, cy;
    struct Quad q;
    struct Pt *p;
    s32 i;

    if (self->identity == 0) {
        c = self->c;
        s = -self->s;
    } else {
        c = 1.0f;
        s = 0.0f;
    }
    y0 = *miny;
    x0 = *minx;
    x1 = *maxx;
    y1 = *maxy;
    cx = (x0 + x1) * 0.5f;
    cy = (y0 + y1) * 0.5f;
    {
        /* The corners are a plain array of points copied as one block: an
           array initialiser has one clobber fewer than a struct holding the
           array, which leaves the scheduler slot that keeps the two sentinel
           constants adjacent (equal spans, so 999999 gets the lower register). */
        struct Pt t[4] = { { cx, y0 }, { x1, cy }, { cx, y1 }, { x0, cy } };
        *minx = 999999.0f;
        *maxx = -999999.0f;
        q = *(struct Quad *)t;
    }
    *miny = 999999.0f;
    *maxy = -999999.0f;
    p = q.p;
    for (i = 3; i >= 0; i--) {
        f32 px = p->x;
        f32 py = p->y;
        f32 rx = px * c - py * s;
        f32 ry = px * s + py * c;
        p++;
        if (rx < *minx) *minx = rx;
        if (*maxx < rx) *maxx = rx;
        if (ry < *miny) *miny = ry;
        if (*maxy < ry) *maxy = ry;
    }
}
