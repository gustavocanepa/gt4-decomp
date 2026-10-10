typedef int s32;

struct Tmp {
    s32 w[4];
};

struct Obj {
    char pad[0xD0];
    s32 unkD0;
};

extern "C" void func_00427820(Tmp *);
extern "C" void GT4_Motion__MotionSetPlayer__set(Tmp *, s32, s32);
extern "C" s32 func_0042A0C0(Tmp *);

extern "C" s32 func_003EB958(Obj *self) {
    if (self->unkD0 == 0)
        return 0;
    Tmp t;
    func_00427820(&t);
    GT4_Motion__MotionSetPlayer__set(&t, 0, self->unkD0);
    return func_0042A0C0(&t);
}
