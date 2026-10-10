typedef int s32;

struct Inner003EB718 {
    char pad0[0xE0];
    s32 unkE0;
};

struct Obj003EB718 {
    char pad0[0x6C];
    Inner003EB718 *unk6C;
};

extern "C" void RaceBasic__render_panel(Obj003EB718 *arg0);

extern "C" void RaceSolitaire__render_panel(Obj003EB718 *arg0) {
    if (arg0->unk6C->unkE0 == 0) {
        return RaceBasic__render_panel(arg0);
    }
}
