/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mutex {
    void lock() __asm__("func_00576788");
    void unlock() __asm__("func_005767C0");
};

struct Owner;

struct Listener {
    virtual void v0();
    virtual void notify(Owner *o);
};

struct Owner {
    char pad0[0x6C];
    Mutex mutex;
    char pad6D[0x9C - 0x6D];
    Listener *listener;
    char padA0[0xAC - 0xA0];
    int state;
    void func_001029D0() __asm__("func_001029D0");
};

void Owner::func_001029D0() {
    mutex.lock();
    int *p = &state;
    bool b = *p != 3;
    if (b) {
        *p = 2;
        listener->notify(this);
    }
    mutex.unlock();
}
