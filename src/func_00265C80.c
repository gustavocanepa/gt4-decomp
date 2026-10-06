struct VEntry { short delta; short index; int (*fn)(void *, int, void *); };
struct Obj { int a; struct VEntry *vtbl; };
extern int func_005D4AD8(const char *, ...);
int func_00265C80(void *ctx, int arg, struct Obj *o)
{
    struct VEntry *e = &o->vtbl[51];
    int r = e->fn((char *)o + e->delta, arg, ctx);
    func_005D4AD8("status %s\n", r == 0 ? "CONTINUE" : r == 2 ? "FILTER" : "STOP");
    return r;
}
