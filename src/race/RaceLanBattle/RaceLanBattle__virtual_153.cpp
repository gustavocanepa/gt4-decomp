typedef int s32;

extern "C" void AutomobileControlRecord__Manager__load(s32 arg0, s32 arg1, s32 arg2);

extern "C" void RaceLanBattle__virtual_153(s32 arg0, s32 arg1) {
    AutomobileControlRecord__Manager__load(arg0 + 0xF258, arg1 + 0x1AA4, 1);
}
