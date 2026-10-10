extern float *func_00386398(int);
struct S { char pad[8]; int h; };
int func_0040D5C8(struct S *s) { float *p = func_00386398(s->h); if (0.0f < *p) return 0; return 1; }
