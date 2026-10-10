typedef int s32;

struct Obj {
    char pad[0xE418];
    s32 unkE418;
};

extern "C" void RaceBase__setPause(Obj *arg0, s32 arg1);

extern "C" void RaceBasic__setPause(Obj *arg0, s32 arg1) {
    RaceBase__setPause(arg0, (arg0->unkE418 == 0) ? 0 : arg1);
}
