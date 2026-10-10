typedef int s32;

struct Res { s32 m0; s32 m4; s32 pad[2]; };

extern char D_0069F2F8[];
extern "C" void func_0045B768(Res *, void *, char *);

static inline Res *find(Res *r) {
    s32 ok = r->m4 >= 0;
    return ok ? r : 0;
}

extern "C" s32 func_0033ACB0(void *a) {
    Res r;
    func_0045B768(&r, a, D_0069F2F8);
    return find(&r) != 0;
}
