typedef int s32;

struct Obj {
    char pad0[0xA8];
    s32 unkA8;
};

extern "C" void *func_001C7468(Obj *arg0)
{
    return (char *)arg0 + arg0->unkA8 * 0x54;
}
