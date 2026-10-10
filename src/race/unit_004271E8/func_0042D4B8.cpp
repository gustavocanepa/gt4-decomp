struct Group {
    char pad0[0x14];
    unsigned short count;
    short pad16;
    void **items;
};

extern "C" void func_0042DA58(void *item, float t);

extern "C" void func_0042D4B8(Group *g, float t)
{
    for (int i = 0; i < g->count; i++)
        func_0042DA58(g->items[i], t);
}
