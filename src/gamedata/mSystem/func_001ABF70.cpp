typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mSystem__ClassID_;

extern "C" void func_001ABF70(void) {
    mSystem__ClassID_ = func_00324F98();
}
