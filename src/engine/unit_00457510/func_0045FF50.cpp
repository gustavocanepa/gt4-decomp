struct Pair {
    int a, b;
    Pair(int x, int y) : a(x), b(y) {}
    Pair(const Pair &o) : a(o.a), b(o.b) {}
};

struct Table {
    int pad0[3];
    int count;
    int def;
    Pair items[1];
};

extern Table *D_00623998;

extern "C" Pair func_0045FF50(int index)
{
    Table *t = D_00623998;
    if (t == 0)
        return Pair(0, 0);
    if (index == -1)
        return Pair(t->items[0].a, t->def);
    if (index >= t->count)
        return Pair(0, 0);
    return t->items[index];
}
