/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0034AA88(void *self, int *a, float *b, float *c);

static inline void setf(float *p, float v) { *p = v; }

extern "C" int func_003FD528(void *self, int *a, float *b, float *c) {
    int ok = 0;
    *a = 0;
    setf(c, 0.0f);
    setf(b, 0.0f);
    if (func_0034AA88(self, a, b, c)) {
        if (*b < 20.0f)
            ok = 1;
    }
    return ok;
}
