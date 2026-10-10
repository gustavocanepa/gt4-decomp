typedef int s32;

struct Inner_003870B8 {
    char pad0[0xDC];
    s32 unkDC;
};

struct Obj_003870B8 {
    char pad0[0x6C];
    Inner_003870B8 *unk6C;
};

extern "C" void GranTurismo4__GameObjectBase__controlFetch(void);

extern "C" void RaceGTmode__controlFetch(Obj_003870B8 *arg0) {
    if (arg0->unk6C->unkDC == 0) {
        GranTurismo4__GameObjectBase__controlFetch();
    }
}
