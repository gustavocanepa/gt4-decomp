extern int func_001F1368(void *arg0);
extern void func_00215298(int arg0);
extern int func_004F51C0(void *arg0);

struct S_00645D18
{
    char pad[0x1F0];
    int unk1F0;
};

struct S_00645570
{
    char pad[0x5A8];
    S_00645D18 *unk5A8;
};

extern S_00645570 D_00645570;

int func_001F40E8(void *arg0)
{
    while (!func_004F51C0(&D_00645570))
        func_00215298(1);

    if (func_001F1368(arg0) == 0)
    {
        return -1;
    }
    return D_00645570.unk5A8->unk1F0;
}
