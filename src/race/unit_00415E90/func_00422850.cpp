typedef unsigned int u128 __attribute__((mode(TI)));
union Quat {
    float v[4];
    u128 q;
};

static inline Quat *rot(Quat *q, int k, float s, float c)
{
    Quat t;
    t.v[0] = c * q->v[0] + s * q->v[2];
    t.v[k] = s * q->v[3] + c * q->v[k];
    t.v[2] = -s * q->v[0] + c * q->v[2];
    t.v[3] = c * q->v[3] - s * q->v[k];
    q->q = t.q;
    return q;
}

extern "C" Quat *func_00422850(Quat *q, float s, float c)
{
    return rot(q, 1, s, c);
}
