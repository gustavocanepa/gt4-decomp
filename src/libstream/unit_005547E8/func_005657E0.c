/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Obj {
    char pad0[0x4C];
    int result[2];
    int flag[2];
    int sema;
} Obj;

int func_00578500(int sema);
int func_00578480(int sema);

int func_005657E0(Obj *o, int i, int *out) {
    *out = -1;
    func_00578500(o->sema);
    if (o->flag[i])
        o->flag[i] = 0;
    *out = o->result[i];
    func_00578480(o->sema);
    return *out == -1 ? 3 : 0;
}
