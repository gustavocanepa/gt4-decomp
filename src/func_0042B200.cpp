struct Item { char pad[0x10]; const char *name; char pad2[0x0C]; };
struct List { short pad; unsigned short count; int pad4; Item *items; };
extern "C" int func_0057F238(const char *, const char *);

extern "C" int func_0042B200(List *l, const char *name)
{
    for (int i = 0; i < l->count; i++) {
        Item *e = l->items;
        e += i;
        if (func_0057F238(name, e->name) == 0) return i;
    }
    return -1;
}
