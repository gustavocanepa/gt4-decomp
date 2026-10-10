typedef int s32;

struct Obj;

extern "C" void *RaceBase__getInput(Obj *self, s32 id);
extern "C" void *RaceSolitaire__getInput(Obj *self, s32 id);
extern "C" void *RaceSolitaire__getInputGhost(Obj *self, s32 id);

extern "C" void *RaceSolitaire__getInput_2(Obj *self, s32 id) {
    switch (id) {
    case 0x100:
        return RaceSolitaire__getInput(self, id);
    case 1:
        return RaceSolitaire__getInputGhost(self, id);
    default:
        return RaceBase__getInput(self, id);
    }
}
