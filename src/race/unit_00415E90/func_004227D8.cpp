typedef int u128 __attribute__((mode(TI)));

union V4 {
    float v[4];
    u128 q;
};

extern "C" V4 *func_004227D8(V4 *q, float a, float b) {
    V4 t;
    int i = 1;
    t.v[0] = a * q->v[3] + b * q->v[0];
    t.v[i] = b * q->v[i] - a * q->v[2];
    t.v[2] = a * q->v[i] + b * q->v[2];
    t.v[3] = b * q->v[3] - a * q->v[0];
    q->q = t.q;
    return q;
}
