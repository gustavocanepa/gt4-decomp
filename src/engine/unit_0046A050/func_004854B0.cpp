extern "C" void *func_004A5B70(int);

struct Pool {
    int a;
    int count;
    void *head;
    void *base;
    Pool(int a, int count) __asm__("func_004854B0");
};

Pool::Pool(int a_, int count_) {
    a = a_;
    count = count_;
    head = func_004A5B70((count_ * 24 + 15) >> 4);
    base = head;
}
