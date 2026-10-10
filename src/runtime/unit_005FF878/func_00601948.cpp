struct Block { long long w[0x102]; };
struct Owner { char pad[0x90]; Block block; };

extern "C" void func_00601948(Owner *o, const Block *b)
{
    o->block = *b;
}
