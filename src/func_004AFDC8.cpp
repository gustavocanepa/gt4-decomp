/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64;

struct Callback_004AFDC8 {
    void (*fn)(void);
    int arg;
    Callback_004AFDC8(void (*f)(void), int a) : fn(f), arg(a) {}
};

struct Obj_004AFDC8 {
    char pad0[0x18];
    Callback_004AFDC8 m18;
    char pad20[8];
    u64 m28;
    Callback_004AFDC8 m30;
};

extern "C" void func_004AF740(Obj_004AFDC8 *o);
extern "C" void func_004AFA88(void);

extern "C" void func_004AFDC8(Obj_004AFDC8 *o) {
    func_004AF740(o);
    o->m28 = 0;
    o->m30 = Callback_004AFDC8(0, 0);
    o->m18 = Callback_004AFDC8(func_004AFA88, 0);
}
