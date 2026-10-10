struct Result {
    int m0;
    int index;
    int pad[2];
};

struct Data {
    int w[20];
};

extern char D_0069F318[];

extern "C" void func_0045B368(Result *r, void *key, void *o, void *table);
extern "C" void func_0033ACF0(Data *d, void *o);
extern "C" void func_0033B0E8(void *out, Data *d);

extern "C" int func_0033A488(void *o, void *key, void *out) {
    Result r;
    func_0045B368(&r, key, o, D_0069F318);
    if (r.index < 0)
        return 0;
    Data d;
    func_0033ACF0(&d, o);
    func_0033B0E8(out, &d);
    return 1;
}
