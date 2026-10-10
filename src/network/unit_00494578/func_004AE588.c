typedef int s32;
typedef struct P { s32 a; s32 b; } P;
void func_004AE5C0(void *a, s32 b, P *c);
void *func_004AE588(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    P p;
    p.a = arg2;
    p.b = arg3;
    func_004AE5C0(arg0, arg1, &p);
    return arg0;
}
