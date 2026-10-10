struct Vec3 { float x, y, z; };
static inline float rsqrtf_(float a, float b)
{
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" void func_003E8DE0(void *self, const Vec3 *c, Vec3 *p, float r)
{
    float dx = p->x - c->x;
    float dy = p->y - c->y;
    float dz = p->z - c->z;
    float d2 = dx * dx + dy * dy + dz * dz;
    if (r * r < d2) {
        float s = rsqrtf_(r, d2);
        p->x = c->x + dx * s;
        p->y = c->y + dy * s;
        p->z = c->z + dz * s;
    }
}
