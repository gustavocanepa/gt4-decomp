typedef int s32;

extern "C" void mColorWindow__setColor_2(s32 arg0, s32 arg1, s32 arg2);

extern "C" void mColorWindow__setColor(s32 arg0, s32 arg1) {
    mColorWindow__setColor_2(arg0, arg1, -1);
}
