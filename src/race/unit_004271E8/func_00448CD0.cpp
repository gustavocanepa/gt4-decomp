typedef long s64;

struct Obj {
    int f0;
    int f4;
    s64 id;
};

extern "C" void *D_00623808;
extern "C" int SPEC_DATABASE__DatabaseTable__getRow(void *mgr, int id, int arg);

extern "C" bool func_00448CD0(Obj *o, int arg) {
    s64 id = o->id;
    if (id == -1) {
        return false;
    }
    return SPEC_DATABASE__DatabaseTable__getRow(D_00623808, (int)(id & 0xFFFFFFFF), arg) != 0;
}
