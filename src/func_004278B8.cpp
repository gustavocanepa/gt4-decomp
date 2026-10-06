typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct B {
    char pad[0x1C];
    u32 entries;
};

struct A {
    void *unk0;
    B *b;
};

extern "C" s32 func_00427848(void *arg0, s32 arg1);
extern "C" s32 func_00427778(void *arg0);

extern "C" s32 func_004278B8(struct A *arg0, s32 arg1)
{
    s32 off = arg1 << 4;

    if (arg1 < 0) {
        return 0;
    }

    {
        struct B *b = arg0->b;
        u32 addr = off + b->entries;
        s16 val = *(s16 *)(addr + 4);
        return func_00427848(arg0, val);
    }
}

extern "C" s32 func_00427900(struct A *arg0)
{
    s32 v0 = func_00427778(arg0->unk0);
    return func_004278B8(arg0, v0);
}
