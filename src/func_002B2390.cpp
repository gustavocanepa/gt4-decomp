struct Obj;
extern "C" float func_002B1FE0(Obj *o);
extern "C" float func_002D4980(Obj *o);
extern "C" int func_002B2310(Obj *o);
extern "C" float func_002B2340(Obj *o);

extern "C" float func_002B2390(Obj *o)
{
    float w = func_002B1FE0(o) + func_002D4980(o);
    int n = func_002B2310(o);
    return w * (n - 1) + func_002B2340(o);
}
