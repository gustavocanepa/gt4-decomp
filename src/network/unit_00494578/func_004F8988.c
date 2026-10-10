typedef int s32;
typedef struct E { s32 a, b, c, d; } E;
typedef struct Q { E e[32]; s32 n; } Q;
void func_004F8988(Q *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->e[arg0->n].a = arg1;
    arg0->e[arg0->n].b = arg2;
    arg0->e[arg0->n].c = arg3;
    arg0->e[arg0->n].d = arg4;
    arg0->n++;
}
