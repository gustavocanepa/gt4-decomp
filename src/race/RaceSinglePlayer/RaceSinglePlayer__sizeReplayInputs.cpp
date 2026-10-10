typedef int s32;

extern "C" void AutomobileControlRecord__Manager__size(s32 arg0, s32 arg1);

extern "C" void RaceSinglePlayer__sizeReplayInputs(s32 arg0) {
    AutomobileControlRecord__Manager__size(arg0 + 0x124A0, 1);
}
