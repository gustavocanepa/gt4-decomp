typedef int s32;

struct S001C4BA8 {
    char pad0[0x20];
    s32 unk298;
};

extern "C" void func_005C1628(struct S001C4BA8 *arg0);
extern "C" char D_00688FC0;

extern "C" void func_004AF708(struct S001C4BA8 *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk298 = (s32)&D_00688FC0;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
