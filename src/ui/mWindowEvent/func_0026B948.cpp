typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mWindowEvent__ClassID_;

extern "C" void func_0026B948(void) {
    mWindowEvent__ClassID_ = func_00324F98();
}
