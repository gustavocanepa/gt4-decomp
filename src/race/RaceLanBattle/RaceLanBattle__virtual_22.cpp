typedef int s32;

struct S { char pad[0xE440]; s32 unkE440; };

extern "C" s32 RaceLanBattle__virtual_22(S *arg0) {
    return arg0->unkE440 == 2;
}
