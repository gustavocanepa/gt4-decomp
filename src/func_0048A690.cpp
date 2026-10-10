struct Quat { float x, y, z, w; };
struct Vec3 { float x, y, z; };

extern "C" void func_0048A690(const Quat *q, Vec3 *out)
{
    float x = q->x, y = q->y, z = q->z, w = q->w;
    float ox = 2.0f * (x * y - z * w);
    float oz = 2.0f * (y * z + x * w);
    float oy = 2.0f * (0.5f - z * z - x * x);
    out->x = ox;
    out->y = oy;
    out->z = oz;
}
