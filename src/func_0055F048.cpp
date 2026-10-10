extern "C" int func_0055F018(void *dev, int reg);

extern "C" int func_0055F048(void *dev, int reg)
{
    int lo = func_0055F018(dev, reg * 2);
    int hi = func_0055F018(dev, reg * 2 + 1);
    return lo | (hi << 8);
}
