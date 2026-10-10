extern "C" int func_00559A18(int, int, int);
extern "C" void func_0055AD20(void *, int, int, float);

struct Obj {
    char pad[0x60];
    int m60;
    int m64;
    int m68;
};

extern "C" void func_0055B1E0(Obj *o, int a, int b, int c) {
    int v = func_00559A18(a, b, c);
    if (v != 0) {
        func_0055AD20(o, v, a, 240.0f);
        o->m60 = 2;
        o->m68 = 0;
        return;
    }
    o->m60 = 0;
}
