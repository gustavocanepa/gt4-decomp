struct Obj {
    char pad[0x674];
    int count;
    char pad2[0x24];
    int misses;
};

extern "C" int func_001D33B0(Obj *o, int i);

extern "C" void func_001D3410(Obj *o)
{
    for (int i = 0; i < o->count; i++) {
        if (func_001D33B0(o, i))
            return;
    }
    o->misses++;
}
