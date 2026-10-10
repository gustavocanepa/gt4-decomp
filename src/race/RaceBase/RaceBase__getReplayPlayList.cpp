typedef int s32;

extern "C" void GranTurismo4__BGMPlayList__setDefault(s32 arg0, s32 arg1);

extern "C" void RaceBase__getReplayPlayList(s32 arg0, s32 arg1) {
    GranTurismo4__BGMPlayList__setDefault(arg1, 0);
}
