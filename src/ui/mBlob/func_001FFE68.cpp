typedef int s32;

extern "C" s32 func_00324F98(void);
extern s32 mBlob__ClassID_;

extern "C" void func_001FFE68(void) {
    mBlob__ClassID_ = func_00324F98();
}
