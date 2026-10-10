typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mRaceRecord__ClassID_;

extern "C" void func_001A5E10(void) {
    mRaceRecord__ClassID_ = func_00324F98();
}
