/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x, y, z, w; };
struct IVec4 { int x, y, z, w; };

struct Obj {
    int id;
    float dirX;
    float dirY;
    float angle;
    int m10;
    int m14;
    Vec4 a;
    Vec4 b;
    int m38;
    int m3C;
    IVec4 c;
    int m50;
};

/* Tag for "fill with zero". The tag object is a local of the caller: an empty class still gets
 * a stack slot, which is the original's otherwise unused 0x10 frame. */
struct Zero {};

static inline float fsqrt(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

static inline void fill(Vec4 *v, Zero) { v->x = 0.0f; v->y = 0.0f; v->z = 0.0f; v->w = 0.0f; }

/* Leaves x as it is. */
static inline void clear(IVec4 *v) { v->y = 0; v->z = 0; v->w = 0; }

/* Make the direction a unit vector; a zero vector becomes (1, 0). */
static inline void normalizeDir(Obj *o) {
    float len = fsqrt(o->dirX * o->dirX + o->dirY * o->dirY);
    if (len > 0.0f) {
        o->dirX = o->dirX / len;
        o->dirY = o->dirY / len;
    } else {
        o->dirX = 1.0f;
        o->dirY = 0.0f;
    }
}

/* Initialise the object with an id and a direction, everything else cleared. */
extern "C" void func_0026EE28(Obj *self, int id, float dirX, float dirY) {
    Zero zero;

    self->id = id;
    self->dirX = dirX;
    self->dirY = dirY;
    self->angle = 0.0f;
    self->m10 = 0;
    self->m14 = 1;
    fill(&self->a, zero);
    fill(&self->b, zero);
    self->m38 = 0;
    self->m3C = 0;
    clear(&self->c);
    self->m50 = 0;
    normalizeDir(self);
}
