typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 hFileIO__ClassID_;

extern "C" void func_002F6680(void) {
    hFileIO__ClassID_ = func_00324F98();
}
