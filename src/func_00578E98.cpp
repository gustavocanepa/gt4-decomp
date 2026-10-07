typedef int s32;

struct Obj {
    char pad0[0x18];
    void *unk18;
    char unk1C[1];
};

extern void *D_00689E80;
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_0057B310(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void func_00578E98(struct Obj *arg0, s32 arg1)
{
    arg0->unk18 = &D_00689E80;
    func_00574DA8(&arg0->unk1C, 2);
    func_0057B310(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
