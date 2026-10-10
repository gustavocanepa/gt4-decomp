/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

s32 func_0055F048(void *dev, s32 reg);

s32 func_0055F0A0(void *dev, s32 index) {
    s32 reg = index * 2;
    s32 lo = func_0055F048(dev, reg);
    s32 hi = func_0055F048(dev, reg + 1);
    return lo | (hi << 16);
}
