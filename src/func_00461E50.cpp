struct Obj {
    int m0;
    int m4;
};

extern "C" int func_00461C00(int v);
extern "C" void func_00461568(Obj *o, int v);
extern "C" void func_0045FF50(Obj *o, int v);

extern "C" Obj *func_00461E50(Obj *o, int v) {
    switch (func_00461C00(v)) {
    case 0:
        func_00461568(o, v);
        break;
    case 1:
        func_0045FF50(o, v - 10);
        break;
    default:
        o->m0 = 0;
        o->m4 = 0;
        break;
    }
    return o;
}
