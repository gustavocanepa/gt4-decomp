extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);

struct Lock {
    int w[4];
};

struct LockGuard {
    Lock *lock;
    LockGuard(Lock *l) : lock(l) { func_00576788(l); }
    ~LockGuard() { func_005767C0(lock); }
};

struct List {
    int head;
    int count;
    int tail;
    char pad[0x1C - 0xC];
    Lock lock;
    void clear() __asm__("func_00613678");
};

void List::clear() {
    LockGuard guard(&lock);
    head = 0;
    count = 0;
    tail = 0;
}
