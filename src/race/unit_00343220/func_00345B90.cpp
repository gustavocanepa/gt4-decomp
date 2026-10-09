typedef int s32;

struct Obj {
    s32 unk0;
    char pad4[0x48 - 0x4];
    s32 unk48;
    s32 unk4C;
};

extern "C" void func_00345B90(Obj *arg0, s32 arg1, s32 arg2)
{
    arg0->unk48 = arg1;
    arg0->unk4C = arg2;
    arg0->unk0 = arg1 + 8;
}
