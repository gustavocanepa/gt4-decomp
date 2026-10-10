/* compiler: ee-gcc2.96-nogcse */
struct List {
    int count;
    int pad4;
    void **items;
};

struct World {
    char pad0[0x60];
    List *cars;
};

struct RaceBase {
    char pad0[0x6C];
    World *world;
};

extern "C" void RaceEntryCar__flushSound(void *car);

extern "C" void RaceBase__flushSound(RaceBase *self)
{
    World *w = self->world;
    int n = w->cars->count;
    for (int i = 0; i < n; i++)
        RaceEntryCar__flushSound(w->cars->items[i]);
}
