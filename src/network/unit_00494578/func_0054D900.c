typedef int s32;
typedef struct { s32 (*f)(s32 a, s32 b); s32 a; } Hook;
extern Hook D_0064C488;
s32 func_0054D900(void) {
    return D_0064C488.f(D_0064C488.a, 0);
}
