typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mSound__ClassID_;

extern "C" void func_0023DF38(void) {
    mSound__ClassID_ = func_00324F98();
}
