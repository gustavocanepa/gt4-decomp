struct Item { char d[0x20]; };
struct List {
    int count;
    Item items[1];
};
extern "C" void func_003B7B70(void *ctx, Item *item);

extern "C" void func_00397BA0(List *l, void *ctx)
{
    for (int i = 0; i < l->count; i++)
        func_003B7B70(ctx, &l->items[i]);
}
