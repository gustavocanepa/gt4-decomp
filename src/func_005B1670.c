/* compiler: ee-gcc2.9-991111 */
struct Item {
    int key;
    char pad4[0x38 - 4];
    struct Item *next;
};

struct Group {
    char pad0[8];
    struct Item *items;
    char padC[0x14 - 0xC];
    struct Group *next;
};

struct Owner {
    char pad0[0x28];
    struct Group *groups;
};

struct Item *func_005B1670(int key, struct Owner *o) {
    struct Group *g;
    struct Item *it;
    for (g = o->groups; g; g = g->next) {
        for (it = g->items; it; it = it->next) {
            if (it->key == key) {
                return it;
            }
        }
    }
    return 0;
}
