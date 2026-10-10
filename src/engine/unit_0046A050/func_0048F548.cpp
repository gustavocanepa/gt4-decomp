struct Item {
    int handle;
    char pad[0xC];
};

struct List {
    char pad[0xC];
    int count;
    char pad2[4];
    Item items[1];
};

extern "C" void func_0048F548(List *l, void (*fn)(int))
{
    if (fn) {
        int n = l->count;
        for (int i = 0; i < n; i++)
            fn(l->items[i].handle);
    }
}
