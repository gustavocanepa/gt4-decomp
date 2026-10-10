struct Plane {
    float a, b, c, d;
};

struct Vec3 {
    float x, y, z;
};

extern "C" int func_003FDC88(Plane *planes, Vec3 *p)
{
    for (int i = 0; i < 6; i++, planes++) {
        if (planes->a * p->x + planes->b * p->y + planes->c * p->z + planes->d > 0.0f)
            return 0;
    }
    return 1;
}
