typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mGameInputAnalog__ClassID_;

extern "C" void func_0029A670(void) {
    mGameInputAnalog__ClassID_ = func_00324F98();
}
