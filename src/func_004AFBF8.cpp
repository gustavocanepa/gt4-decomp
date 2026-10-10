/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned long u64;

extern "C" void func_004AFA88(void *arg);

/* A callback slot: function and argument. */
struct Callback {
    void (*fn)(void *);
    s32 arg;
    Callback() : fn(0), arg(0) {}
    Callback(void (*f)(void *)) : fn(f), arg(0) {}
};

/* The base class, named after its constructor so that __13func_004AF6D0 resolves; its vptr
   sits after its 0x20 bytes of data. */
struct func_004AF6D0 {
    s32 m0, m4, m8, mC, m10, m14;
    Callback cb;
    func_004AF6D0();
    virtual ~func_004AF6D0();
};

/* Named after its vtable so the compiler-made vptr store _vt$10D_00688FA0 resolves. */
struct D_00688FA0 : func_004AF6D0 {
    u64 m28;
    Callback cb30;
    s32 m38;
    D_00688FA0();
    virtual ~D_00688FA0();
};

D_00688FA0::D_00688FA0() : m28(0), m38(0) {
    cb = Callback(func_004AFA88);
}
