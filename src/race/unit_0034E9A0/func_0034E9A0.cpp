struct Params {
    int v[8];
};

extern "C" void func_00343490(Params *);
extern "C" float func_00359568(void *obj, float x);
extern "C" float func_00350868(void *table, Params *p);
extern char D_00620320[];

extern "C" float func_0034E9A0(void *obj, Params *p, float x)
{
    Params def;
    func_00343490(&def);
    if (p == 0)
        p = &def;
    float a = func_00359568(obj, x);
    return a * func_00350868(D_00620320, p);
}
