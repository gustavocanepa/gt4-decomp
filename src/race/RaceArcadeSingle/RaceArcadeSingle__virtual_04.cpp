typedef int s32;

struct Inner_003870B8 {
    char pad0[0xDC];
    s32 unkDC;
};

struct Obj_003870B8 {
    char pad0[0x6C];
    Inner_003870B8 *unk6C;
};

extern "C" void CarIconMaker__virtual_04(void);

extern "C" void RaceArcadeSingle__virtual_04(Obj_003870B8 *arg0) {
    if (arg0->unk6C->unkDC == 0) {
        CarIconMaker__virtual_04();
    }
}
