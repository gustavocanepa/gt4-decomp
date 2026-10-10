struct Str;
struct Obj;

extern "C" Str *func_005A609C(Str *s, const char *t);
extern "C" Str *func_005A5DC8(Str *s, const char *t);
extern "C" const char *func_00397848(Obj *o);

extern const char *D_006214E8[];
extern int D_006214FC;
extern const char D_006A03A8[];

extern "C" Str *func_00397868(Obj *o, Str *s) {
    func_005A609C(s, D_006214E8[D_006214FC]);
    func_005A5DC8(s, D_006A03A8);
    func_005A5DC8(s, func_00397848(o));
    return s;
}
