typedef int s32;

extern "C" void AutomobileControlRecord__Recorder__write(s32 arg0);

extern "C" void RaceInput__recordControl(s32 arg0) {
    AutomobileControlRecord__Recorder__write(arg0 + 0xDC);
}
