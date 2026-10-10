struct Rect {
    short x0, y0, x1, y1;
};

extern "C" void func_004B6038(void *self, Rect *a, Rect *b) {
    if (a->y1 - a->x1 > 0) {
        a->y1--;
        if (a->y1 < a->x1)
            a->y1 = a->x1;
        b->x1--;
        if (b->y1 < b->x1)
            b->x1 = b->y1;
    }
}
