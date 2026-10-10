struct Item { int a, b; };
struct List { Item items[400]; unsigned int count; };

extern "C" void func_001D1478(Item *dst, const Item *src);

extern "C" int func_001D1280(List *l, const Item *it)
{
    if (l->count >= 400 || it == 0)
        return 0;
    func_001D1478(&l->items[l->count++], it);
    return 1;
}
