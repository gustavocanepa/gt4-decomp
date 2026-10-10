struct Quat {
    float x, y, z, w;
};

struct Mat3 {
    float m[9];
};

extern "C" void func_0048A810(const Quat *q, Mat3 *out) {
    float x2 = q->x + q->x;
    float y2 = q->y + q->y;
    float z2 = q->z + q->z;
    float xx = x2 * q->x;
    float xy = x2 * q->y;
    float xz = x2 * q->z;
    float yy = y2 * q->y;
    float yz = y2 * q->z;
    float zz = z2 * q->z;
    float wx = x2 * q->w;
    float wy = y2 * q->w;
    float wz = z2 * q->w;
    out->m[0] = 1.0f - yy - zz;
    out->m[3] = xy - wz;
    out->m[6] = xz + wy;
    out->m[1] = xy + wz;
    out->m[4] = 1.0f - zz - xx;
    out->m[7] = yz - wx;
    out->m[2] = xz - wy;
    out->m[5] = yz + wx;
    out->m[8] = 1.0f - xx - yy;
}
