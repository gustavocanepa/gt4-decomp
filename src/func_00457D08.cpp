struct List {
    int count;
    void *items[1];
};

extern "C" void func_00457798(void *item, void *a, void *b);

extern "C" void func_00457D08(List *l, void *a, void *b) {
    for (int i = 0; i < l->count; i++)
        func_00457798(l->items[i], a, b);
}
