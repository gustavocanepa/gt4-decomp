typedef int s32;

extern "C" void mWidget__setActive(s32 arg0, s32 arg1);

extern "C" s32 mScrollArrow__onLeave(s32 arg0) {
    mWidget__setActive(arg0, 0);
    return 1;
}
