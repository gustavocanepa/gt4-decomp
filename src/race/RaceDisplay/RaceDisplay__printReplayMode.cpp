typedef int s32;
typedef float f32;

extern "C" void RaceDisplay__put_replay_mode_display(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);

extern "C" void RaceDisplay__printReplayMode(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    RaceDisplay__put_replay_mode_display(arg0, arg1, (arg2 == 0) ? (s32)0x80000000 : arg2, (arg3 == 0) ? (s32)0x800086E6 : arg3, 3.0f);
}
