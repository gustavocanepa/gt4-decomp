extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);

struct Lock {
    int w[4];
};

struct LockGuard {
    Lock *lock;
    LockGuard(Lock *l) : lock(l) { func_00576100(l); }
    ~LockGuard() { func_00576140(lock); }
};

struct List {
    int head;
    int count;
    int tail;
    char pad[0x1C - 0xC];
    Lock lock;
    void clear() __asm__("func_00613220");
};

void List::clear() {
    LockGuard guard(&lock);
    head = 0;
    count = 0;
    tail = 0;
}
