typedef int s32;

struct Obj {
    char pad0[0x123CC];
    char unk123CC[4];
};

extern "C" void *RaceBase__getInput(Obj *self, s32 id);

extern "C" void *RaceSinglePlayer__getInput(Obj *self, s32 id) {
    if (id == 0x100) {
        return self->unk123CC;
    }
    return RaceBase__getInput(self, id);
}
