typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mLoggerControl__ClassID_;

extern "C" void func_0011E9F8(void) {
    mLoggerControl__ClassID_ = func_00324F98();
}
