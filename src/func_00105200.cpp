struct Part {
    int w[15];
    Part &operator=(const Part &o) __asm__("func_00105378");
};

struct Parts {
    Part a;
    Part b;
    Part c;
    Parts &operator=(const Parts &o) __asm__("func_00105200");
};

Parts &Parts::operator=(const Parts &o) {
    a = o.a;
    b = o.b;
    c = o.c;
    return *this;
}
