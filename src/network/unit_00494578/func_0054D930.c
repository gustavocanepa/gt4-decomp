typedef int s32;
typedef struct { s32 (*f)(s32 a, s32 b); s32 a; } Hook;
extern Hook D_0064C490;
s32 func_0054D930(void) {
    return D_0064C490.f(D_0064C490.a, 0);
}
