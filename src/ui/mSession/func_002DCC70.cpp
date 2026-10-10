typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mSession__ClassID_;

extern "C" void func_002DCC70(void) {
    mSession__ClassID_ = func_00324F98();
}
