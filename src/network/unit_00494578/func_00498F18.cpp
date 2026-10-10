/* compiler: ee-gcc2.96-nogcse */
struct Item {
    char data[0x20];
};

struct List {
    unsigned short count;
    short pad2;
    Item *items;
};

struct Obj {
    char pad0[0x24];
    List *list;
};

extern "C" void func_00498E48(Item *item);

extern "C" void func_00498F18(Obj *o)
{
    List *l = o->list;
    if (l == 0 || l->items == 0)
        return;
    for (int i = 0; i < l->count; i++)
        func_00498E48(&l->items[i]);
}
