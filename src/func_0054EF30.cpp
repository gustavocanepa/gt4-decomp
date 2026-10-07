typedef int s32;

struct Struct_0054EF30 {
    char pad0[0x3E8];
    s32 unk3E8;
};

extern s32 func_0054FD10(s32);
extern s32 D_0064C4B8;
extern s32 D_0064C4B0;

s32 func_0054EF30(struct Struct_0054EF30 *arg0)
{
    if (D_0064C4B8 == 0 && D_0064C4B0 != 0) {
        return func_0054FD10(arg0->unk3E8);
    }
    return 0;
}
