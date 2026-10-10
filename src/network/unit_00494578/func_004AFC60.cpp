/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned long u64;

extern "C" void func_004AFA88(void *arg);

struct Callback {
    void (*fn)(void *);
    s32 arg;
    Callback() : fn(0), arg(0) {}
    Callback(void (*f)(void *)) : fn(f), arg(0) {}
    Callback(const Callback &o) : fn(o.fn), arg(o.arg) {}
};

struct func_004AF6D0 {
    s32 m0, m4, m8, mC, m10, m14;
    Callback cb;
    func_004AF6D0();
    virtual ~func_004AF6D0();
};

struct D_00688FA0 : func_004AF6D0 {
    u64 m28;
    Callback cb30;
    s32 m38;
    D_00688FA0(const Callback &c, s32 v);
    virtual ~D_00688FA0();
};

D_00688FA0::D_00688FA0(const Callback &c, s32 v) : m28(0), cb30(c), m38(0) {
    cb = Callback(func_004AFA88);
    m10 = v;
}
