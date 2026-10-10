typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mEvent__ClassID_;

extern "C" void func_0028E2B0(void) {
    mEvent__ClassID_ = func_00324F98();
}
