typedef int s32;

struct S_Vec
{
    char pad0[4];
    s32 *unk4;
    s32 *unk8;
};

s32 func_002EF9B0(void *arg0)
{
    struct S_Vec *v = (struct S_Vec *)((char *)arg0 + 0x10);
    return v->unk8 - v->unk4;
}
