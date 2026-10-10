extern "C" void func_00578B10(int);

struct Th {
    char pad[0x694];
    volatile int state;
    volatile int req;
};

extern "C" void func_001D26F8(Th *t) {
    if (t->state != 2 && t->req != 2)
        t->req = 2;
    while (t->state != 2)
        func_00578B10(16000);
}
