/* compiler: ee-gcc2.96-no-strict-aliasing */
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Item;

struct Alloc {
};

struct ItemVector {
    Alloc a;
    Item **start;
    Item **finish;
    Item **eos;
    int size() const { return finish - start; }
    void insert_aux(Item **pos, Item *const &x) __asm__("func_005F01D8");
    void push_back(Item *const &x) {
        if (finish != eos) {
            new (finish) Item *(x);
            ++finish;
        } else {
            insert_aux(finish, x);
        }
    }
};

struct Obj {
    char pad[0x10];
    ItemVector items;
};

extern "C" int func_00318E68(Obj *o, Item *item) {
    int index = o->items.size();
    o->items.push_back(item);
    return index;
}
