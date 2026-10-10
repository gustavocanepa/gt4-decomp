typedef int u128 __attribute__((mode(TI)));

union Quat {
    float v[4];
    u128 q;
};

extern "C" void func_00487830(Quat *q, float angle);
extern "C" Quat Numerical_Math__Quaternion__rotate(const Quat *q, const void *axis);

static inline void fromAngle(Quat *q, const float &a) { func_00487830(q, a); }

extern "C" void func_00423E60(Quat *out, int unused, const void *axis, const float *angle, Quat *rot) {
    Quat q;
    float a = *angle;
    fromAngle(&q, a);
    const Quat &r = Numerical_Math__Quaternion__rotate(&q, axis);
    out->q = r.q;
    if (rot)
        rot->q = q.q;
}
