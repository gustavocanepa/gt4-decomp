typedef unsigned int u32;
typedef int s32;

struct Obj { char pad[0x20]; s32 unk20; };

extern "C" s32 RaceDisplay__is_play_mode(Obj *arg0) {
    return (u32)arg0->unk20 < 2U;
}
