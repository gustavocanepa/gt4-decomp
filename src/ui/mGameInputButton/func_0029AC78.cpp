typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mGameInputButton__ClassID_;

extern "C" void func_0029AC78(void) {
    mGameInputButton__ClassID_ = func_00324F98();
}
