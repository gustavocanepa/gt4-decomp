typedef int s32;

struct Obj {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void RaceBase__virtual_39();
extern "C" void CarIconMaker__structor_1(void *arg0, s32 arg1);

extern "C" void RaceArcadeSingle__virtual_39(Obj *arg0) {
    Obj *s0 = arg0;
    RaceBase__virtual_39();
    CarIconMaker__structor_1((char *)s0 + 0x22708, s0->unk6C);
}
