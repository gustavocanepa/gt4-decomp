typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mBox__ClassID_;

extern "C" void func_00200B70(void) {
    mBox__ClassID_ = func_00324F98();
}
