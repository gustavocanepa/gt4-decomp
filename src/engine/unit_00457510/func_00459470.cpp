struct Vec3 { float x, y, z; };

extern "C" Vec3 *func_00459470(Vec3 *out, const Vec3 *a, const Vec3 *b, float t)
{
    float s = 1.0f - t;
    float x = a->x * t + b->x * s;
    float y = a->y * t + b->y * s;
    float z = a->z * t + b->z * s;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}
