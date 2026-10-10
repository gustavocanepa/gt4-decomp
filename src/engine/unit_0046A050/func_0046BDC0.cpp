struct Key { char pad[0x14]; float value; };
struct Chunk { char pad[0xC]; short count; };
struct Iter { void *base; int count; int stride; int pad; };
extern "C" void func_00469F08(Iter *it, Chunk *c, int kind);
extern "C" Key *func_00469FC8(Iter *it, int i);

extern "C" float func_0046BDC0(Chunk *c, int i)
{
    if (!c->count)
        return 0.0f;
    Iter it;
    func_00469F08(&it, c, 4);
    int neg;
    if (i < 0)
        neg = 1;
    else
        neg = 0;
    i += neg * it.count;
    return func_00469FC8(&it, i)->value;
}
