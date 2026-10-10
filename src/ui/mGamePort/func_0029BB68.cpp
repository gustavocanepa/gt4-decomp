typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mGamePort__ClassID_;

extern "C" void func_0029BB68(void) {
    mGamePort__ClassID_ = func_00324F98();
}
