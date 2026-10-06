struct Vec3 { float x, y, z; };

void func_003E2140(Vec3 *out, Vec3 *a, Vec3 *b)
{
    out->x = a->y * b->z - a->z * b->y;
    out->y = a->z * b->x - a->x * b->z;
    out->z = a->x * b->y - a->y * b->x;
}
