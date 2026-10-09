typedef int s32;

struct Obj_003BE0F0 {
    char pad0[0x6C];
    s32 unk6C;
};

extern "C" void RaceBase__virtual_39(struct Obj_003BE0F0 *arg0);
extern "C" void CarIconMaker__structor_1(void *arg0, s32 arg1);

extern "C" void RaceMachineTest__virtual_39(struct Obj_003BE0F0 *arg0) {
    RaceBase__virtual_39(arg0);

    CarIconMaker__structor_1((char *)arg0 + 0xF140, arg0->unk6C);
}
