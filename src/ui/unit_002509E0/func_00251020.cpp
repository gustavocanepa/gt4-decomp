typedef float f32;
typedef int s32;

struct Parent {
    char pad0x2C[0x2C];
    f32 table[1][4];
};

extern "C" f32 func_00251020(struct Parent *arg0, s32 arg1, s32 arg2)
{
    return arg0->table[arg1][arg2];
}
