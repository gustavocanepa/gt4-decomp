typedef int s32;

struct Obj {
    char pad0[0x10];
    void (*unk10)(void *);
};

extern struct Obj *D_0064A55C;

s32 func_0050F780(void)
{
    struct Obj *temp_v0 = D_0064A55C;

    if (temp_v0 != 0) {
        temp_v0->unk10(temp_v0);
    }
    D_0064A55C = 0;
    return 0;
}
