typedef int s32;

struct Obj {
    s32 a;
    s32 b;
    s32 arr[4];
    s32 c;
    s32 d;
    s32 e;
};

extern "C" void func_0043A078(Obj *o) {
    s32 i;
    o->a = 0;
    o->b = 0;
    o->c = 0;
    o->d = 0;
    o->e = 0;
    for (i = 3; i >= 0; i--)
        o->arr[i] = 0;
}
