typedef int s32;

extern "C" s32 RaceBase__getSignal(void *arg0);
extern "C" void func_00574F58(void *arg0);

extern "C" s32 RaceBase__signalHandler(void *arg0) {
    func_00574F58((char *)arg0 + 0xCE4);
    return RaceBase__getSignal(arg0);
}
