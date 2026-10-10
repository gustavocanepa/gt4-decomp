typedef int s32;

struct Obj {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void RaceBase__postInitialize();
extern "C" void CarIconMaker__structor_1(void *arg0, s32 arg1);

extern "C" void RaceArcade__postInitialize(Obj *arg0) {
    Obj *s0 = arg0;
    RaceBase__postInitialize();
    CarIconMaker__structor_1((char *)s0 + 0x22708, s0->unk6C);
}
