
struct Vec { float x, y, z; };

extern "C" void func_0048C188(Vec *out, const Vec *v, const Vec *fallback) {
    if (v->x != 0.0f) {
        out->x = -v->y;
        out->y = v->x;
        out->z = 0.0f;
    } else {
        const float &y = v->y;
        if (y != 0.0f) {
            out->x = 0.0f;
            out->y = -v->z;
            out->z = y;
        } else if (v->z != 0.0f) {
            out->x = v->z;
            out->y = 0.0f;
            out->z = -v->x;
        } else {
            out->x = fallback->x;
            out->y = fallback->y;
            out->z = fallback->z;
        }
    }
}
