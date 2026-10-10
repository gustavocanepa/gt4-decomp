struct Stream {
    int base;
    int pad4;
    int size;
    int padC;
    int index;
    int pad14[2];
    volatile int waitSema;
    int lockSema;
};

extern "C" int func_005ADCE0(int sema);
extern "C" int func_005ADCC0(int sema);
extern "C" int func_005647F0(Stream *s);

extern "C" int func_00564888(Stream *s) {
    do {
        if (s->waitSema != -1)
            func_005ADCE0(s->waitSema);
    } while (s->waitSema != -1 && func_005647F0(s));
    func_005ADCE0(s->lockSema);
    int pos = s->base + s->index * s->size;
    func_005ADCC0(s->lockSema);
    return pos;
}
