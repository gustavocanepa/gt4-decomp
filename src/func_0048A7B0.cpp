struct Quat { float x, y, z, w; };
struct Vec4 { float x, y, z, w; };

extern "C" void func_0048A7B0(const Quat *q, Vec4 *out, float w4)
{
    float x = q->x, y = q->y, z = q->z, w = q->w;
    float ox = 2.0f * (x * z + y * w);
    float oy = 2.0f * (y * z - x * w);
    float oz = 2.0f * (0.5f - x * x - y * y);
    out->x = ox;
    out->y = oy;
    out->z = oz;
    out->w = w4;
}
