struct Item { char pad[0x30]; int type; };
struct Handler { void (*fn)(Item *); int a, b; };
struct Mgr { char pad[0x50]; Handler handlers[1]; };
extern char D_00655340[];
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0055C808(Mgr *, Item *);

extern "C" void func_0055C648(Mgr *m, Item *it, int flag)
{
    func_00576100(D_00655340);
    Handler *h = m->handlers;
    h += it->type;
    void (*fn)(Item *) = h->fn;
    if (fn) fn(it);
    if (flag) func_0055C808(m, it);
    func_00576140(D_00655340);
}
