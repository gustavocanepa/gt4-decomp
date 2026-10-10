struct Obj {
    char pad[0x674];
    int count;
    char pad2[0x24];
    int misses;
};

extern "C" int func_001D3480(Obj *o, int i);

extern "C" void func_001D3548(Obj *o)
{
    for (int i = 0; i < o->count; i++) {
        if (func_001D3480(o, i))
            return;
    }
    o->misses++;
}
