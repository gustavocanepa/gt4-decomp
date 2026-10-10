typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mKeyReleaseEvent__ClassID_;

extern "C" void func_002AB440(void) {
    mKeyReleaseEvent__ClassID_ = func_00324F98();
}
