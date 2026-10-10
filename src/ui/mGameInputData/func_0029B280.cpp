typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mGameInputData__ClassID_;

extern "C" void func_0029B280(void) {
    mGameInputData__ClassID_ = func_00324F98();
}
