struct Stats { int a, b, c, d, e, f; };
extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" char D_00655340[];

extern "C" void func_00559918(Stats *s)
{
    func_00576100(D_00655340);
    s->a = 0;
    s->b = 0;
    s->e = 0;
    s->f = 0;
    s->c = 0;
    s->d = 0;
    func_00576140(D_00655340);
}
