typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mCallbackEvent__ClassID_;

extern "C" void func_00281C48(void) {
    mCallbackEvent__ClassID_ = func_00324F98();
}
