typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mScriptEvent__ClassID_;

extern "C" void func_00239E40(void) {
    mScriptEvent__ClassID_ = func_00324F98();
}
