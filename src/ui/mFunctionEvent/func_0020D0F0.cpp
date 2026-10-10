typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mFunctionEvent__ClassID_;

extern "C" void func_0020D0F0(void) {
    mFunctionEvent__ClassID_ = func_00324F98();
}
