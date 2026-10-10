typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mDatabase__ClassID_;

extern "C" void func_001B41F8(void) {
    mDatabase__ClassID_ = func_00324F98();
}
