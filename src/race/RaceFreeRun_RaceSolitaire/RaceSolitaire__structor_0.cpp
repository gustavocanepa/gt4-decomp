/* RaceFreeRun/RaceSolitaire constructor body: base ctor (returns this), vtable, member ctors at
 * fixed offsets, then member setup; ends in a sibling call. Callee return types (s32 for the
 * base ctor and func_005A48D8) and the argument forms decide the register homes. */
typedef short s16;
typedef int s32;

#define F(base, type, off) (*(type *)((char *)(base) + (off)))

typedef struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32); } VEntry;

extern "C" s32 RaceBasic__structor_0(void *);
extern "C" void SimplePause__structor_0(void *);
extern "C" void func_0055F9F8(void *);
extern "C" void RaceInput__structor_0(void *);
extern "C" void func_00444190(void *);
extern "C" void func_00343490(void *);
extern "C" void func_00346758(void *);
extern "C" void func_003BDA08(void *);
extern "C" s32 func_0033D958(s32);
extern "C" s32 func_0055F420(s32);
extern "C" void func_00109A28(void *, void *);
extern "C" void func_00346808(void *, s32);
extern "C" void func_00346890(void *, s32);
extern "C" void *func_00346A28(void *);
extern "C" s32 func_005A48D8(void *, s32, s32);
extern "C" void RaceFreeRun__virtual_153(void *);
extern "C" void func_0038B850(void *, void *);
extern char RaceSolitaire__vtable[];
extern char *D_00622F4C;

extern "C" void RaceSolitaire__structor_0(char *self) {
    char *mEFE0 = self + 0xEFE0;
    char *mEF70 = self + 0xEF70;
    char *mE48C = self + 0xE48C;
    char *mEC10 = self + 0xEC10;
    char *mEDC0 = self + 0xEDC0;
    char *mE440, *mE66C, *mE84C, *mEA2C, *obj;
    VEntry *ent;
    RaceBasic__structor_0(self);
    F(self, char *, 0x64) = RaceSolitaire__vtable;
    SimplePause__structor_0(mE440 = self + 0xE440);
    mE66C = self + 0xE66C;
    mE84C = self + 0xE84C;
    func_0055F9F8(self + 0xE44C);
    mEA2C = self + 0xEA2C;
    RaceInput__structor_0(mE48C);
    RaceInput__structor_0(mE66C);
    RaceInput__structor_0(mE84C);
    RaceInput__structor_0(mEA2C);
    func_00444190(mEC10);
    func_00343490(self + 0xED88);
    func_00444190(mEDC0);
    func_00343490(self + 0xEF38);
    func_00346758(mEF70);
    func_00346758(mEFE0);
    func_003BDA08(self + 0xF058);
    F(mE48C, s32, 0) = func_0055F420(func_0033D958(0));
    obj = D_00622F4C + 0x39E80;
    ent = (VEntry *)(*(char **)obj + 0x40);
    F(mE48C, s32, 0x194) = ent->fn(obj + ent->delta, 0);
    F(self, s32, 0x58) = (s32)(self + 0xE44C);
    func_00109A28(self, mE48C);
    {
        char *q = self + 0xE560;
        F(q, s32, 4) = 0;
        func_00346808(q, 0);
    }
    F(mEFE0, s32, 4) = 2;
    func_00346808(mEFE0, 1);
    func_00346890(mEFE0, 1);
    F(mE48C, char *, 0x148) = mEFE0;
    F(mEF70, s32, 4) = 2;
    func_00346808(mEF70, 1);
    func_00346890(mEF70, 2);
    {
        char *q = (char *)func_00346A28(mEF70);
        func_005A48D8(q, 0, 0x14F4);
        F(q, s32, 0x10) = 0x157529FF;
    }
    F(mE48C, char *, 0x144) = mEF70;
    {
        char *q = self + 0xE740;
        F(q, s32, 4) = 0;
        func_00346808(q, 1);
    }
    F(mE66C, s32, 0x1D0) = 1;
    F(self, s32, 0xE924) = 0;
    F(mE84C, s32, 0x1D0) = 1;
    F(self, s32, 0xEB04) = 0;
    F(mEA2C, s32, 0x1D0) = 1;
    F(self, s32, 0xF0FC) = 1;
    F(self, s32, 0xF0F8) = 0;
    func_005A48D8(mEC10, 0, 0x1B0);
    func_005A48D8(mEDC0, 0, 0x1B0);
    F(self, s32, 0xF054) = 0;
    F(self, s32, 0xF050) = 1;
    F(self, s32, 0xF0EC) = 0;
    F(self, s32, 0xF0F0) = 0;
    F(self, s32, 0xF100) = 0;
    F(self, s32, 0xF104) = 0;
    RaceFreeRun__virtual_153(self);
    return func_0038B850(self, mE440);
}


