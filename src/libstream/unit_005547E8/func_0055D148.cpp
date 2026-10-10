struct Obj { void *root; };
struct Count { int n; int max; };
typedef int (*Cb)(void *, void *);
extern "C" int func_0055D120(void *, void *);
extern "C" int func_0055D028(void *, void *);
extern "C" void func_0055C9A0(void *root, Obj *o, Cb visit, Count *c, Cb filter);

extern "C" int func_0055D148(Obj *o, int filtered)
{
    Count c;
    c.n = 0;
    c.max = 0x7FFFFFFF;
    if (filtered)
        func_0055C9A0(o->root, o, func_0055D120, &c, func_0055D028);
    else
        func_0055C9A0(o->root, o, func_0055D120, &c, 0);
    return c.n;
}
