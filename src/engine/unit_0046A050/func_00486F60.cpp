struct Quat {
    float x, y, z, w;
};

extern "C" float func_00486F60(Quat *self, const Quat &q) {
    float n = self->x * self->x + self->y * self->y + self->z * self->z + self->w * self->w;
    if (n != 0.0f) {
        float inv = 1.0f / n;
        float x = -q.x * inv;
        float y = -q.y * inv;
        float z = -q.z * inv;
        float w = q.w * inv;
        self->x = x;
        self->y = y;
        self->z = z;
        self->w = w;
    }
    return n;
}
