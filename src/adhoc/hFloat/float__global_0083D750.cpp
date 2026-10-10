extern "C" void func_002F9360(void *v, float f);
extern "C" void func_002F7B68(void *v, int in_chrg);
extern "C" void func_003285A8(void *obj);
extern "C" void func_003285F8(void *obj);

/* Reference-counted script float value handle. */
struct Handle {
    void *p;
    int pad[3];
    void assign(const Handle &o)
    {
        if (this != &o) {
            void *np = o.p;
            if (np)
                func_003285A8(np);
            if (p)
                func_003285F8(p);
            p = np;
        }
    }
};

extern "C" void float__global_0083D750(Handle *h)
{
    Handle tmp;
    func_002F9360(&tmp, 0.0f);
    h->assign(tmp);
    func_002F7B68(&tmp, 2);
}
