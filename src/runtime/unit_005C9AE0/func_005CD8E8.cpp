/* compiler: ee-gcc2.96-stl */
extern "C" void func_00575DA0(void *p);

template <class T> inline void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
    ~Alloc() {}
};

struct Vec : Alloc {
    int *start;
    int *finish;
    int *eos;
    Vec(const Alloc &a = Alloc()) : start(0), finish(0), eos(0) {}
    ~Vec()
    {
        if (start)
            func_00575DA0(start);
    }
    void swap(Vec &x)
    {
        ::swap(start, x.start);
        ::swap(finish, x.finish);
        ::swap(eos, x.eos);
    }
};

extern "C" void func_005CD8E8(Vec *v) {
    Vec tmp;
    tmp.swap(*v);
}
