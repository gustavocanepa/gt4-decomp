struct Cursor {
    int f0;
    int count;
    int f8;
    int cur;
    void set(int v) {
        if (v >= 0 && v < count) {
            cur = v;
        }
    }
};

extern "C" bool func_00400408(Cursor *c, int delta) {
    int old = c->cur;
    int v = old + delta;
    if (v < 0) {
        v = c->count - 1;
    }
    if (v >= c->count) {
        v = 0;
    }
    c->set(v);
    return old != c->cur;
}
