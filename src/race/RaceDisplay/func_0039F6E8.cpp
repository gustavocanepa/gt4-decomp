typedef int s32;

extern "C" void RaceEntryCar__update(s32 arg0);
extern "C" void func_004A5400(void);

extern "C" void func_0039F6E8(void) {
    RaceEntryCar__update(1);
    func_004A5400();
    RaceEntryCar__update(0);
}
